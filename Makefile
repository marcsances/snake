all: snake

clean:
	rm -f snake cutils.o drawprocs.o iqueue.o

snake: snake.c cutils.o drawprocs.o iqueue.o
	gcc snake.c cutils.o drawprocs.o iqueue.o -o snake

iqueue.o: iqueue.c iqueue.h
	gcc -c iqueue.c -o iqueue.o

cutils.o: cutils.c cutils.h
	gcc -c cutils.c -o cutils.o

drawprocs.o: drawprocs.c
	gcc -c drawprocs.c -o drawprocs.o