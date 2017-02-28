CC=gcc
CFLAGS= -Wall -std=c99


exelParse: exelParse.o
	$(CC) -o exelParse  exelParse.o

exelParse.o: exelParse.c
	$(CC) $(CFLAGS) -c exelParse.c
clean:
	rm exelParse exelParse.o



