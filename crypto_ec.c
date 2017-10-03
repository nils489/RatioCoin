#include "crypto_ec.h"

EC_KEY *create_rc_ec_keypair(const uint8_t *priv_bytes) {
	EC_KEY *key;
	BIGNUM *priv;
	BN_CTX *bnctx;
	const EC_GROUP *generator;
	EC_POINT *pub;

	// init empty OpenSSL EC keypair
	key = EC_KEY_new_by_curve_name(NID_secp256k1);

	// set private key
	priv = BN_new();
	BN_bin2bn(priv_bytes, 32, priv);
	EC_KEY_set_private_key(key, priv);

	// derive public key from private key and generator
	bnctx = BN_CTX_new();
	BN_CTX_start(bnctx);

	generator = EC_KEY_get0_group(key);
	pub = EC_POINT_new(generator);
	EC_POINT_mul(generator, pub, priv, NULL, NULL, bnctx);
	EC_KEY_set_public_key(key, pub);

	// cleanup
	EC_POINT_free(pub);
	BN_CTX_end(bnctx);
	BN_CTX_free(bnctx);
	BN_clear_free(priv);

	printf("WARNING! Naive implementation of create_rc_ec_keypair!\n");
	return key;
}

EC_KEY *create_rc_ec_pubkey(const uint8_t *pub_bytes, size_t pub_len) {
	EC_KEY *key;
	const uint8_t *pub_bytes_local;
	key = EC_KEY_new_by_curve_name(NID_secp256k1);
	pub_bytes_local = pub_bytes;
	o2i_ECPublicKey(&key, &pub_bytes_local, pub_len);

	printf("WARNING! Naive implementation of create_rc_ec_pubkey!\n");
	return key;
}
