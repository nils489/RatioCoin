#include <stdio.h>
#include "blockchain.h"
#include "proofofwork.h"

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
	retM = mine();
	if(!retM) {
		printf("Mining successful\n");
	} else {
		printf("Mining failed\n");
	}
	return 0;
}
