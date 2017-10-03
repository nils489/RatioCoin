#ifndef __TEST_H_INCLUDED
#define __TEST_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "crypto_ec.h"
#include "hash_utils.h"

int run_tests();
EC_KEY *create_keypair(uint8_t *priv_bytes, size_t len);

#endif
