#include <stdio.h>
#include "blockchain.h"
#include "proofofwork.h"
#include "crypto_ec.h"

int mine() {
	int retBC, retPW;

	printf("Mining ...\n");
	retBC = checkBlockChain();
	retPW = proofWork();
	return retBC || retPW;
}

int create_keypair() {
	const uint8_t dummy_bytes=5;
	EC_KEY *key;
	key = create_rc_ec_keypair(&dummy_bytes);
	if(key==NULL) {
		printf("WARNING! No key generated!\n");
	}
	return 0;
}


int main() {
	int retM;

	printf("Welcome to the RatioCoin client!\n");

	printf("Creating keypair ...\n");
	create_keypair();

	retM = mine();
	if(!retM) {
		printf("Mining successful\n");
	} else {
		printf("Mining failed\n");
	}
	return 0;
}
