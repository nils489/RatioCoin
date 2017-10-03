#ifndef CRYPTO_EC_H_INCLUDED
#define CRYPTO_EC_H_INCLUDED

#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/ecdsa.h>

EC_KEY *create_rc_ec_keypair(const uint8_t *priv_bytes);
EC_KEY *create_rc_ec_pubkey(const uint8_t *pub_bytes, size_t pub_len);

#endif
