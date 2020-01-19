#Makefile

CC=gcc
CFLAGS= -Wall


all: frequency

frequency: main.o frequency.o 
	$(CC) $(CFLAGS) -fPIC -o frequency main.o frequency.o 

main.o: main.c trie.h
	$(CC) $(CFLAGS) -c main.c

frequency.o: frequency.c trie.h
	$(CC) $(CFLAGS) -c frequency.c


.PHONY: clean all 

clean:
	rm -f *.o frequency