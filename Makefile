rc_client: blockchain.o proofofwork.o main.c
	gcc -Wall -o rc_client main.c blockchain.o proofofwork.o

blockchain.o: blockchain.h blockchain.c
	gcc -Wall -g -c blockchain.c

proofofwork.o: proofofwork.h proofofwork.c
	gcc -Wall -g -c proofofwork.c
