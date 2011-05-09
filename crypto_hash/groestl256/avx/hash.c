/* groestl-asm.c     Feb 2011
 *
 * Groestl implementation for different versions.
 * Author: Günther A. Roland
 *
 * Based on the inline assembly version by:
 * Krystian Matusiewicz
 *
 * This code is placed in the public domain
 */

#include "hash.h"
#include "groestl-version.h"

#ifdef TASM
  #ifdef VAES
    #include "groestl-asm-aes.h"
  #else
    #ifdef VAVX
      #include "groestl-asm-avx.h"
    #else
      #ifdef VVPERM
        #include "groestl-asm-vperm.h"
      #else
        #error NO VERSION SPECIFIED (-DV[AES/AVX/VVPERM])
      #endif
    #endif
  #endif
#else
  #ifdef TINTR
    #ifdef VAES
      #include "groestl-intr-aes.h"
    #else
      #ifdef VAVX
        #include "groestl-intr-avx.h"
      #else
        #ifdef VVPERM
          #include "groestl-intr-vperm.h"
        #else
          #error NO VERSION SPECIFIED (-DV[AES/AVX/VVPERM])
        #endif
      #endif
    #endif
  #else
    #error NO TYPE SPECIFIED (-DT[ASM/INTR])
  #endif
#endif


/* digest up to len bytes of input (full blocks only) */
void Transform(hashState *ctx,
	       const u8 *in, 
	       unsigned long long len) {

#if (LENGTH <= 256)
    /* increment block counter */
    ctx->block_counter += len/SIZE512;
    
    /* digest message, one block at a time */
    for (; len >= SIZE512; len -= SIZE512, in += SIZE512)
#ifdef __x86_64    
      TF512((u64*)in);
#else
      TF512((u32*)in);
#endif

#endif
#if (LENGTH > 256)
    /* increment block counter */
    ctx->block_counter += len/SIZE1024;
    
    /* digest message, one block at a time */
    for (; len >= SIZE1024; len -= SIZE1024, in += SIZE1024)
#ifdef __x86_64    
      TF1024((u64*)in);
#else
      TF1024((u32*)in);
#endif
#endif

    asm volatile ("emms");
}

/* given state h, do h <- P(h)+h */
void OutputTransformation(hashState *ctx) {
  int j;

  /* determine variant */
#if (LENGTH <= 256)
    OF512();
#endif
#if (LENGTH > 256)
    OF1024();
#endif

    asm volatile ("emms");
}

/* initialise context */
HashReturn Init(hashState* ctx) {
  u8 i = 0;

  /* output size (in bits) must be a positive integer less than or
     equal to 512, and divisible by 8 */
  if (LENGTH <= 0 || (LENGTH%8) || LENGTH > 512)
    return BAD_HASHLEN;

  /* set number of state columns and state size depending on
     variant */
  #if (LENGTH <= 256)
    ctx->columns = COLS512;
    ctx->statesize = SIZE512;
    ctx->v = SHORT;
  #endif
  #if (LENGTH > 256)
    ctx->columns = COLS1024;
    ctx->statesize = SIZE1024;
    ctx->v = LONG;
  #endif

  SET_CONSTANTS();

  /* allocate memory for state and data buffer */
#ifdef __x86_64    
  ctx->chaining = (u64*) GLOBAL_CV_PTR;
#else
  ctx->chaining = (u32*) GLOBAL_CV_PTR;
#endif
  ctx->buffer = malloc(ctx->statesize);
  if (ctx->chaining == NULL || ctx->buffer == NULL)
    return FAIL;

  /* set initial value */
  ctx->chaining[ctx->columns-1] = U64BIG((u64)LENGTH);

  INIT_CV();

  /* set other variables */
  ctx->buf_ptr = 0;
  ctx->block_counter = 0;
  ctx->bits_in_last_byte = 0;

  return SUCCESS;
}

/* update state with databitlen bits of input */
HashReturn Update(hashState* ctx,
		  const BitSequence* input,
		  DataLength databitlen) {
  int index = 0;
  int msglen = (int)(databitlen/8);
  int rem = (int)(databitlen%8);

  /* non-integral number of message bytes can only be supplied in the
     last call to this function */
  if (ctx->bits_in_last_byte) return FAIL;

  /* if the buffer contains data that has not yet been digested, first
     add data to buffer until full */
  if (ctx->buf_ptr) {
    while (ctx->buf_ptr < ctx->statesize && index < msglen) {
      ctx->buffer[(int)ctx->buf_ptr++] = input[index++];
    }
    if (ctx->buf_ptr < ctx->statesize) {
      /* buffer still not full, return */
      if (rem) {
        ctx->bits_in_last_byte = rem;
        ctx->buffer[(int)ctx->buf_ptr++] = input[index];
      }
      return SUCCESS;
    }

    /* digest buffer */
    ctx->buf_ptr = 0;
    Transform(ctx, ctx->buffer, ctx->statesize);
  }

  /* digest bulk of message */
  Transform(ctx, input+index, msglen-index);
  index += ((msglen-index)/ctx->statesize)*ctx->statesize;

  /* store remaining data in buffer */
  while (index < msglen) {
    ctx->buffer[(int)ctx->buf_ptr++] = input[index++];
  }

  /* if non-integral number of bytes have been supplied, store
     remaining bits in last byte, together with information about
     number of bits */
  if (rem) {
    ctx->bits_in_last_byte = rem;
    ctx->buffer[(int)ctx->buf_ptr++] = input[index];
  }
  return SUCCESS;
}

#define BILB ctx->bits_in_last_byte

/* finalise: process remaining data (including padding), perform
   output transformation, and write hash result to 'output' */
HashReturn Final(hashState* ctx,
		 BitSequence* output) {
  int i, j = 0, hashbytelen = LENGTH/8;
  u8 *s = (BitSequence*)ctx->chaining;

  /* pad with '1'-bit and first few '0'-bits */
  if (BILB) {
    ctx->buffer[(int)ctx->buf_ptr-1] &= ((1<<BILB)-1)<<(8-BILB);
    ctx->buffer[(int)ctx->buf_ptr-1] ^= 0x1<<(7-BILB);
    BILB = 0;
  }
  else ctx->buffer[(int)ctx->buf_ptr++] = 0x80;

  /* pad with '0'-bits */
  if (ctx->buf_ptr > ctx->statesize-LENGTHFIELDLEN) {
    /* padding requires two blocks */
    while (ctx->buf_ptr < ctx->statesize) {
      ctx->buffer[(int)ctx->buf_ptr++] = 0;
    }
    /* digest first padding block */
    Transform(ctx, ctx->buffer, ctx->statesize);
    ctx->buf_ptr = 0;
  }
  while (ctx->buf_ptr < ctx->statesize-LENGTHFIELDLEN) {
    ctx->buffer[(int)ctx->buf_ptr++] = 0;
  }

  /* length padding */
  ctx->block_counter++;
  ctx->buf_ptr = ctx->statesize;
  while (ctx->buf_ptr > ctx->statesize-LENGTHFIELDLEN) {
    ctx->buffer[(int)--ctx->buf_ptr] = (u8)ctx->block_counter;
    ctx->block_counter >>= 8;
  }

  /* digest final padding block */
  Transform(ctx, ctx->buffer, ctx->statesize);
  /* perform output transformation */
  OutputTransformation(ctx);

  /* store hash result in output */
  for (i = ctx->statesize-hashbytelen; i < ctx->statesize; i++,j++) {
    output[j] = s[i];
  }

  /* zeroise relevant variables and deallocate memory */
  
  for (i = 0; i < ctx->columns; i++) {
    ctx->chaining[i] = 0;
  }
  
  for (i = 0; i < ctx->statesize; i++) {
    ctx->buffer[i] = 0;
  }
  //free(ctx->chaining);
  free(ctx->buffer);

  return SUCCESS;
}

/* hash bit sequence */
HashReturn Hash(int hashbitlen,
		const BitSequence* data, 
		DataLength databitlen,
		BitSequence* hashval) {
  HashReturn ret;
  hashState context;

  /* initialise */
  if ((ret = Init(&context)) != SUCCESS)
    return ret;

  /* process message */
  if ((ret = Update(&context, data, databitlen)) != SUCCESS)
    return ret;

  /* finalise */
  ret = Final(&context, hashval);

  return ret;
}

/* eBash API */
#ifdef crypto_hash_BYTES
int crypto_hash(unsigned char *out, const unsigned char *in, unsigned long long inlen)
{
  if (Hash(crypto_hash_BYTES * 8, in, inlen * 8,out) == SUCCESS) return 0;
  return -1;
}
#endif
