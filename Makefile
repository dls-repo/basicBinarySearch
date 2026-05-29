CC = gcc
CFLAGS = -Wall -Wextra -g

program: main.o mergesort.o arrayutils.o binarysearch.o
	$(CC) $(CFLAGS) -o program main.o mergesort.o arrayutils.o binarysearch.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

mergesort.o: mergesort.c mergesort.h
	$(CC) $(CFLAGS) -c mergesort.c

arrayutils.o: arrayutils.c arrayutils.h
	$(CC) $(CFLAGS) -c arrayutils.c

binarysearch.o: binarysearch.c binarysearch.h
	$(CC) $(CFLAGS) -c binarysearch.c

clean:
	rm -f *.o program
