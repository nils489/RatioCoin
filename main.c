#include <stdio.h>
#include <string.h>
#include "blockchain.h"
#include "proofofwork.h"
#include "crypto_ec.h"
#include "hash_utils.h"
#include "test.h"

int mine() {
	int retBC, retPW;

	printf("Mining ...\n");
	retBC = checkBlockChain();
	retPW = proofWork();
	return retBC || retPW;
}

int main() {
	int retM;

	printf("Welcome to the RatioCoin client!\n");

	run_tests();

	retM = mine();
	if(!retM) {
		printf("Mining successful\n");
	} else {
		printf("Mining failed\n");
	}
	return 0;
}
