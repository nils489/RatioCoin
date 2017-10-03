#include "hash_utils.h"

void rc_ec_sha256(uint8_t *digest, const char *message, size_t len) {
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, message, len);
	SHA256_Final(digest, &ctx);
}

void rc_ec_hash256(uint8_t *digest, const char *message, size_t len) {
	uint8_t tmp_digest[32];
	char in_digest[32];

	tmp_digest[0] = 0;
	in_digest[0]  =0;

	rc_ec_sha256(tmp_digest, message, len);
	*in_digest = (char) *tmp_digest;
	rc_ec_sha256(digest, in_digest, len);
}

