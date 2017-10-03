#include "test.h"

EC_KEY *create_keypair(uint8_t *priv_bytes, size_t len) {
	EC_KEY *key;
	key = NULL;
	if(32 == len) {
		key = create_rc_ec_keypair(priv_bytes);
	}
	if(key==NULL) {
		printf("WARNING! No key generated!\n");
	}

	return key;
}


int run_tests() {
	uint8_t priv_bytes[32] = {
	0x16, 0x26, 0x07, 0x83, 0xe4, 0x0b, 0x16, 0x73,
	0x16, 0x73, 0x62, 0x2a, 0xc8, 0xa5, 0xb0, 0x45,
	0xfc, 0x3e, 0xa4, 0xaf, 0x70, 0xf7, 0x27, 0xf3,
	0xf9, 0xe9, 0x2b, 0xdd, 0x3a, 0x1d, 0xdc, 0x42
	};

	const char message[] = "This is a very confidential message\n";

	EC_KEY *key;
	int verified;
	uint8_t digest[32];
	ECDSA_SIG *signature;

	printf("Creating keypair ...\n");
	key = create_keypair(priv_bytes, 32);
	printf("Hashing message ...\n");
	rc_ec_hash256(digest, message, strlen(message));
	printf("Signing message ...\n");
	signature = ECDSA_do_sign(digest, sizeof(digest), key);
	printf("Verifying signature ...\n");
	verified = ECDSA_do_verify(digest, sizeof(digest), signature, key);
	if(verified) {
		printf("The signature is valid\n");
	} else if (verified == 0) {
		printf("The signature is invalid\n");
	} else {
		printf("ERROR! Unexpected error in ECDSA_do_verify (OPENSSL)");
	}
	return 0;
}
