#ifndef HASH_UTILS_H_INCLUDED
#define HASH_UTILS_H_INCLUDED

#include <openssl/sha.h>
#include <openssl/ripemd.h>

void rc_ec_sha256(uint8_t *digest, const char *message, size_t len);
void rc_ec_hash256(uint8_t *digest, const char *message, size_t len);

#endif
