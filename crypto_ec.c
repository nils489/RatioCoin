#include "crypto_ec.h"

EC_KEY *create_rc_ec_keypair(const uint8_t *priv_bytes) {
	EC_KEY *key;
	BIGNUM *priv;
	BN_CTX *bnctx;
	const EC_GROUP *generator;
	EC_POINT *pub;

	// init empty OpenSSL EC keypair
	key = EC_KEY_new_by_curve_name(NID_secp256k1);
	if(NULL == key) {
		printf("ERROR! Unable to create EC keypair from curve name (OPENSSL, secp256k1)\n");
	}

	// set private key
	priv = BN_new();
	if(NULL == priv) {
		printf("ERROR! Unable to create BIGNUM (OPENSSL)\n");
	}
	BN_bin2bn(priv_bytes, 32, priv);
	if(!EC_KEY_set_private_key(key, priv)){
		printf("ERROR! Unable to set private key (OPENSSL)\n");
	}

	// derive public key from private key and generator
	bnctx = BN_CTX_new();
	if(NULL == bnctx) {
		printf("ERROR! Unable to create BN_CTX (OPENSSL)\n");
	}
	BN_CTX_start(bnctx);

	generator = EC_KEY_get0_group(key);
	pub = EC_POINT_new(generator);
	if(NULL == pub) {
		printf("ERROR! Unable to determine public key (OPENSSL)\n");
	}
	if(!EC_POINT_mul(generator, pub, priv, NULL, NULL, bnctx)) {
		printf("ERROR! EC_POINT_mul() failed (OPENSSL)\n");
	}
	if(!EC_KEY_set_public_key(key, pub)) {
		printf("ERROR! Unable to set public key (OPENSSL)\n");
	}

	// cleanup
	EC_POINT_free(pub);
	BN_CTX_end(bnctx);
	BN_CTX_free(bnctx);
	BN_clear_free(priv);

	return key;
}

EC_KEY *create_rc_ec_pubkey(const uint8_t *pub_bytes, size_t pub_len) {
	EC_KEY *key;
	const uint8_t *pub_bytes_local;

	key = EC_KEY_new_by_curve_name(NID_secp256k1);
	if(NULL == key) {
		printf("ERROR! Unable to create EC keypair from curve name (OPENSSL, secp256k1)\n");
	}
	pub_bytes_local = pub_bytes;
	o2i_ECPublicKey(&key, &pub_bytes_local, pub_len);

	return key;
}
