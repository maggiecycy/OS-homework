CC = gcc
CFLAGS = -g -Wall

mymore: mymore.o
	$(CC) $(CFLAGS) mymore.o -o mymore

mymore.o: mymore.c
	$(CC) $(CFLAGS) -c mymore.c

clean:
	rm -f *.o mymore