#include <openssl/rand.h>
#define crypto_encrypt_ronald1024_openssl_MODULUSBITS 1024 
#define crypto_encrypt_ronald1024_openssl_MODULUSBYTES (crypto_encrypt_ronald1024_openssl_MODULUSBITS / 8)

#define crypto_encrypt_ronald1024_openssl_SECRETKEYBYTES (crypto_encrypt_ronald1024_openssl_MODULUSBYTES * 8)
#define crypto_encrypt_ronald1024_openssl_PUBLICKEYBYTES (crypto_encrypt_ronald1024_openssl_MODULUSBYTES)
#define crypto_encrypt_ronald1024_openssl_BYTES (crypto_encrypt_ronald1024_openssl_MODULUSBYTES)
