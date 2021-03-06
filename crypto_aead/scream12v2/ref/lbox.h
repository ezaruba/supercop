/* Scream L-box */

static const crypto_uint16 LBox1[256] = {
	0x0000, 0x385c, 0x52a9, 0x6af5, 0x7bb3, 0x43ef, 0x291a, 0x1146,
	0x96c1, 0xae9d, 0xc468, 0xfc34, 0xed72, 0xd52e, 0xbfdb, 0x8787,
	0xd76d, 0xef31, 0x85c4, 0xbd98, 0xacde, 0x9482, 0xfe77, 0xc62b,
	0x41ac, 0x79f0, 0x1305, 0x2b59, 0x3a1f, 0x0243, 0x68b6, 0x50ea,
	0x3ae0, 0x02bc, 0x6849, 0x5015, 0x4153, 0x790f, 0x13fa, 0x2ba6,
	0xac21, 0x947d, 0xfe88, 0xc6d4, 0xd792, 0xefce, 0x853b, 0xbd67,
	0xed8d, 0xd5d1, 0xbf24, 0x8778, 0x963e, 0xae62, 0xc497, 0xfccb,
	0x7b4c, 0x4310, 0x29e5, 0x11b9, 0x00ff, 0x38a3, 0x5256, 0x6a0a,
	0xe524, 0xdd78, 0xb78d, 0x8fd1, 0x9e97, 0xa6cb, 0xcc3e, 0xf462,
	0x73e5, 0x4bb9, 0x214c, 0x1910, 0x0856, 0x300a, 0x5aff, 0x62a3,
	0x3249, 0x0a15, 0x60e0, 0x58bc, 0x49fa, 0x71a6, 0x1b53, 0x230f,
	0xa488, 0x9cd4, 0xf621, 0xce7d, 0xdf3b, 0xe767, 0x8d92, 0xb5ce,
	0xdfc4, 0xe798, 0x8d6d, 0xb531, 0xa477, 0x9c2b, 0xf6de, 0xce82,
	0x4905, 0x7159, 0x1bac, 0x23f0, 0x32b6, 0x0aea, 0x601f, 0x5843,
	0x08a9, 0x30f5, 0x5a00, 0x625c, 0x731a, 0x4b46, 0x21b3, 0x19ef,
	0x9e68, 0xa634, 0xccc1, 0xf49d, 0xe5db, 0xdd87, 0xb772, 0x8f2e,
	0xfea5, 0xc6f9, 0xac0c, 0x9450, 0x8516, 0xbd4a, 0xd7bf, 0xefe3,
	0x6864, 0x5038, 0x3acd, 0x0291, 0x13d7, 0x2b8b, 0x417e, 0x7922,
	0x29c8, 0x1194, 0x7b61, 0x433d, 0x527b, 0x6a27, 0x00d2, 0x388e,
	0xbf09, 0x8755, 0xeda0, 0xd5fc, 0xc4ba, 0xfce6, 0x9613, 0xae4f,
	0xc445, 0xfc19, 0x96ec, 0xaeb0, 0xbff6, 0x87aa, 0xed5f, 0xd503,
	0x5284, 0x6ad8, 0x002d, 0x3871, 0x2937, 0x116b, 0x7b9e, 0x43c2,
	0x1328, 0x2b74, 0x4181, 0x79dd, 0x689b, 0x50c7, 0x3a32, 0x026e,
	0x85e9, 0xbdb5, 0xd740, 0xef1c, 0xfe5a, 0xc606, 0xacf3, 0x94af,
	0x1b81, 0x23dd, 0x4928, 0x7174, 0x6032, 0x586e, 0x329b, 0x0ac7,
	0x8d40, 0xb51c, 0xdfe9, 0xe7b5, 0xf6f3, 0xceaf, 0xa45a, 0x9c06,
	0xccec, 0xf4b0, 0x9e45, 0xa619, 0xb75f, 0x8f03, 0xe5f6, 0xddaa,
	0x5a2d, 0x6271, 0x0884, 0x30d8, 0x219e, 0x19c2, 0x7337, 0x4b6b,
	0x2161, 0x193d, 0x73c8, 0x4b94, 0x5ad2, 0x628e, 0x087b, 0x3027,
	0xb7a0, 0x8ffc, 0xe509, 0xdd55, 0xcc13, 0xf44f, 0x9eba, 0xa6e6,
	0xf60c, 0xce50, 0xa4a5, 0x9cf9, 0x8dbf, 0xb5e3, 0xdf16, 0xe74a,
	0x60cd, 0x5891, 0x3264, 0x0a38, 0x1b7e, 0x2322, 0x49d7, 0x718b,
};

static const crypto_uint16 LBox2[256] = {
	0x0000, 0x464b, 0xf1af, 0xb7e4, 0xa133, 0xe778, 0x509c, 0x16d7,
	0x7f74, 0x393f, 0x8edb, 0xc890, 0xde47, 0x980c, 0x2fe8, 0x69a3,
	0x6712, 0x2159, 0x96bd, 0xd0f6, 0xc621, 0x806a, 0x378e, 0x71c5,
	0x1866, 0x5e2d, 0xe9c9, 0xaf82, 0xb955, 0xff1e, 0x48fa, 0x0eb1,
	0x7a6f, 0x3c24, 0x8bc0, 0xcd8b, 0xdb5c, 0x9d17, 0x2af3, 0x6cb8,
	0x051b, 0x4350, 0xf4b4, 0xb2ff, 0xa428, 0xe263, 0x5587, 0x13cc,
	0x1d7d, 0x5b36, 0xecd2, 0xaa99, 0xbc4e, 0xfa05, 0x4de1, 0x0baa,
	0x6209, 0x2442, 0x93a6, 0xd5ed, 0xc33a, 0x8571, 0x3295, 0x74de,
	0x701b, 0x3650, 0x81b4, 0xc7ff, 0xd128, 0x9763, 0x2087, 0x66cc,
	0x0f6f, 0x4924, 0xfec0, 0xb88b, 0xae5c, 0xe817, 0x5ff3, 0x19b8,
	0x1709, 0x5142, 0xe6a6, 0xa0ed, 0xb63a, 0xf071, 0x4795, 0x01de,
	0x687d, 0x2e36, 0x99d2, 0xdf99, 0xc94e, 0x8f05, 0x38e1, 0x7eaa,
	0x0a74, 0x4c3f, 0xfbdb, 0xbd90, 0xab47, 0xed0c, 0x5ae8, 0x1ca3,
	0x7500, 0x334b, 0x84af, 0xc2e4, 0xd433, 0x9278, 0x259c, 0x63d7,
	0x6d66, 0x2b2d, 0x9cc9, 0xda82, 0xcc55, 0x8a1e, 0x3dfa, 0x7bb1,
	0x1212, 0x5459, 0xe3bd, 0xa5f6, 0xb321, 0xf56a, 0x428e, 0x04c5,
	0x8ab1, 0xccfa, 0x7b1e, 0x3d55, 0x2b82, 0x6dc9, 0xda2d, 0x9c66,
	0xf5c5, 0xb38e, 0x046a, 0x4221, 0x54f6, 0x12bd, 0xa559, 0xe312,
	0xeda3, 0xabe8, 0x1c0c, 0x5a47, 0x4c90, 0x0adb, 0xbd3f, 0xfb74,
	0x92d7, 0xd49c, 0x6378, 0x2533, 0x33e4, 0x75af, 0xc24b, 0x8400,
	0xf0de, 0xb695, 0x0171, 0x473a, 0x51ed, 0x17a6, 0xa042, 0xe609,
	0x8faa, 0xc9e1, 0x7e05, 0x384e, 0x2e99, 0x68d2, 0xdf36, 0x997d,
	0x97cc, 0xd187, 0x6663, 0x2028, 0x36ff, 0x70b4, 0xc750, 0x811b,
	0xe8b8, 0xaef3, 0x1917, 0x5f5c, 0x498b, 0x0fc0, 0xb824, 0xfe6f,
	0xfaaa, 0xbce1, 0x0b05, 0x4d4e, 0x5b99, 0x1dd2, 0xaa36, 0xec7d,
	0x85de, 0xc395, 0x7471, 0x323a, 0x24ed, 0x62a6, 0xd542, 0x9309,
	0x9db8, 0xdbf3, 0x6c17, 0x2a5c, 0x3c8b, 0x7ac0, 0xcd24, 0x8b6f,
	0xe2cc, 0xa487, 0x1363, 0x5528, 0x43ff, 0x05b4, 0xb250, 0xf41b,
	0x80c5, 0xc68e, 0x716a, 0x3721, 0x21f6, 0x67bd, 0xd059, 0x9612,
	0xffb1, 0xb9fa, 0x0e1e, 0x4855, 0x5e82, 0x18c9, 0xaf2d, 0xe966,
	0xe7d7, 0xa19c, 0x1678, 0x5033, 0x46e4, 0x00af, 0xb74b, 0xf100,
	0x98a3, 0xdee8, 0x690c, 0x2f47, 0x3990, 0x7fdb, 0xc83f, 0x8e74,
};

static const crypto_uint16 LBoxInv1[256] = {
	0x0000, 0xe79e, 0x7704, 0x909a, 0x2ad1, 0xcd4f, 0x5dd5, 0xba4b,
	0x6313, 0x848d, 0x1417, 0xf389, 0x49c2, 0xae5c, 0x3ec6, 0xd958,
	0xdc05, 0x3b9b, 0xab01, 0x4c9f, 0xf6d4, 0x114a, 0x81d0, 0x664e,
	0xbf16, 0x5888, 0xc812, 0x2f8c, 0x95c7, 0x7259, 0xe2c3, 0x055d,
	0xaef6, 0x4968, 0xd9f2, 0x3e6c, 0x8427, 0x63b9, 0xf323, 0x14bd,
	0xcde5, 0x2a7b, 0xbae1, 0x5d7f, 0xe734, 0x00aa, 0x9030, 0x77ae,
	0x72f3, 0x956d, 0x05f7, 0xe269, 0x5822, 0xbfbc, 0x2f26, 0xc8b8,
	0x11e0, 0xf67e, 0x66e4, 0x817a, 0x3b31, 0xdcaf, 0x4c35, 0xabab,
	0x2939, 0xcea7, 0x5e3d, 0xb9a3, 0x03e8, 0xe476, 0x74ec, 0x9372,
	0x4a2a, 0xadb4, 0x3d2e, 0xdab0, 0x60fb, 0x8765, 0x17ff, 0xf061,
	0xf53c, 0x12a2, 0x8238, 0x65a6, 0xdfed, 0x3873, 0xa8e9, 0x4f77,
	0x962f, 0x71b1, 0xe12b, 0x06b5, 0xbcfe, 0x5b60, 0xcbfa, 0x2c64,
	0x87cf, 0x6051, 0xf0cb, 0x1755, 0xad1e, 0x4a80, 0xda1a, 0x3d84,
	0xe4dc, 0x0342, 0x93d8, 0x7446, 0xce0d, 0x2993, 0xb909, 0x5e97,
	0x5bca, 0xbc54, 0x2cce, 0xcb50, 0x711b, 0x9685, 0x061f, 0xe181,
	0x38d9, 0xdf47, 0x4fdd, 0xa843, 0x1208, 0xf596, 0x650c, 0x8292,
	0x82ae, 0x6530, 0xf5aa, 0x1234, 0xa87f, 0x4fe1, 0xdf7b, 0x38e5,
	0xe1bd, 0x0623, 0x96b9, 0x7127, 0xcb6c, 0x2cf2, 0xbc68, 0x5bf6,
	0x5eab, 0xb935, 0x29af, 0xce31, 0x747a, 0x93e4, 0x037e, 0xe4e0,
	0x3db8, 0xda26, 0x4abc, 0xad22, 0x1769, 0xf0f7, 0x606d, 0x87f3,
	0x2c58, 0xcbc6, 0x5b5c, 0xbcc2, 0x0689, 0xe117, 0x718d, 0x9613,
	0x4f4b, 0xa8d5, 0x384f, 0xdfd1, 0x659a, 0x8204, 0x129e, 0xf500,
	0xf05d, 0x17c3, 0x8759, 0x60c7, 0xda8c, 0x3d12, 0xad88, 0x4a16,
	0x934e, 0x74d0, 0xe44a, 0x03d4, 0xb99f, 0x5e01, 0xce9b, 0x2905,
	0xab97, 0x4c09, 0xdc93, 0x3b0d, 0x8146, 0x66d8, 0xf642, 0x11dc,
	0xc884, 0x2f1a, 0xbf80, 0x581e, 0xe255, 0x05cb, 0x9551, 0x72cf,
	0x7792, 0x900c, 0x0096, 0xe708, 0x5d43, 0xbadd, 0x2a47, 0xcdd9,
	0x1481, 0xf31f, 0x6385, 0x841b, 0x3e50, 0xd9ce, 0x4954, 0xaeca,
	0x0561, 0xe2ff, 0x7265, 0x95fb, 0x2fb0, 0xc82e, 0x58b4, 0xbf2a,
	0x6672, 0x81ec, 0x1176, 0xf6e8, 0x4ca3, 0xab3d, 0x3ba7, 0xdc39,
	0xd964, 0x3efa, 0xae60, 0x49fe, 0xf3b5, 0x142b, 0x84b1, 0x632f,
	0xba77, 0x5de9, 0xcd73, 0x2aed, 0x90a6, 0x7738, 0xe7a2, 0x003c,
};

static const crypto_uint16 LBoxInv2[256] = {
	0x0000, 0x1e54, 0xb9be, 0xa7ea, 0x19d8, 0x078c, 0xa066, 0xbe32,
	0xa8a5, 0xb6f1, 0x111b, 0x0f4f, 0xb17d, 0xaf29, 0x08c3, 0x1697,
	0x6abf, 0x74eb, 0xd301, 0xcd55, 0x7367, 0x6d33, 0xcad9, 0xd48d,
	0xc21a, 0xdc4e, 0x7ba4, 0x65f0, 0xdbc2, 0xc596, 0x627c, 0x7c28,
	0x7ee5, 0x60b1, 0xc75b, 0xd90f, 0x673d, 0x7969, 0xde83, 0xc0d7,
	0xd640, 0xc814, 0x6ffe, 0x71aa, 0xcf98, 0xd1cc, 0x7626, 0x6872,
	0x145a, 0x0a0e, 0xade4, 0xb3b0, 0x0d82, 0x13d6, 0xb43c, 0xaa68,
	0xbcff, 0xa2ab, 0x0541, 0x1b15, 0xa527, 0xbb73, 0x1c99, 0x02cd,
	0x7bd6, 0x6582, 0xc268, 0xdc3c, 0x620e, 0x7c5a, 0xdbb0, 0xc5e4,
	0xd373, 0xcd27, 0x6acd, 0x7499, 0xcaab, 0xd4ff, 0x7315, 0x6d41,
	0x1169, 0x0f3d, 0xa8d7, 0xb683, 0x08b1, 0x16e5, 0xb10f, 0xaf5b,
	0xb9cc, 0xa798, 0x0072, 0x1e26, 0xa014, 0xbe40, 0x19aa, 0x07fe,
	0x0533, 0x1b67, 0xbc8d, 0xa2d9, 0x1ceb, 0x02bf, 0xa555, 0xbb01,
	0xad96, 0xb3c2, 0x1428, 0x0a7c, 0xb44e, 0xaa1a, 0x0df0, 0x13a4,
	0x6f8c, 0x71d8, 0xd632, 0xc866, 0x7654, 0x6800, 0xcfea, 0xd1be,
	0xc729, 0xd97d, 0x7e97, 0x60c3, 0xdef1, 0xc0a5, 0x674f, 0x791b,
	0x86d8, 0x988c, 0x3f66, 0x2132, 0x9f00, 0x8154, 0x26be, 0x38ea,
	0x2e7d, 0x3029, 0x97c3, 0x8997, 0x37a5, 0x29f1, 0x8e1b, 0x904f,
	0xec67, 0xf233, 0x55d9, 0x4b8d, 0xf5bf, 0xebeb, 0x4c01, 0x5255,
	0x44c2, 0x5a96, 0xfd7c, 0xe328, 0x5d1a, 0x434e, 0xe4a4, 0xfaf0,
	0xf83d, 0xe669, 0x4183, 0x5fd7, 0xe1e5, 0xffb1, 0x585b, 0x460f,
	0x5098, 0x4ecc, 0xe926, 0xf772, 0x4940, 0x5714, 0xf0fe, 0xeeaa,
	0x9282, 0x8cd6, 0x2b3c, 0x3568, 0x8b5a, 0x950e, 0x32e4, 0x2cb0,
	0x3a27, 0x2473, 0x8399, 0x9dcd, 0x23ff, 0x3dab, 0x9a41, 0x8415,
	0xfd0e, 0xe35a, 0x44b0, 0x5ae4, 0xe4d6, 0xfa82, 0x5d68, 0x433c,
	0x55ab, 0x4bff, 0xec15, 0xf241, 0x4c73, 0x5227, 0xf5cd, 0xeb99,
	0x97b1, 0x89e5, 0x2e0f, 0x305b, 0x8e69, 0x903d, 0x37d7, 0x2983,
	0x3f14, 0x2140, 0x86aa, 0x98fe, 0x26cc, 0x3898, 0x9f72, 0x8126,
	0x83eb, 0x9dbf, 0x3a55, 0x2401, 0x9a33, 0x8467, 0x238d, 0x3dd9,
	0x2b4e, 0x351a, 0x92f0, 0x8ca4, 0x3296, 0x2cc2, 0x8b28, 0x957c,
	0xe954, 0xf700, 0x50ea, 0x4ebe, 0xf08c, 0xeed8, 0x4932, 0x5766,
	0x41f1, 0x5fa5, 0xf84f, 0xe61b, 0x5829, 0x467d, 0xe197, 0xffc3,
};
