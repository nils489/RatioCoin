rc_client: blockchain.o proofofwork.o crypto_ec.o main.c
	gcc -Wall -Wextra -Werror -o rc_client main.c blockchain.o proofofwork.o crypto_ec.o -lssl -lcrypto

blockchain.o: blockchain.h blockchain.c
	gcc -Wall -Wextra -Werror -g -c blockchain.c

proofofwork.o: proofofwork.h proofofwork.c
	gcc -Wall -Wextra -Werror -g -c proofofwork.c

crypto_ec.o: crypto_ec.h crypto_ec.c
	gcc -Wall -Wextra -Werror -g -c crypto_ec.c
