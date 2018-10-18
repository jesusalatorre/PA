all: contador thread2 thread3 thread4 thread4a

contador: contador.c
	gcc contador.c -o contador -lpthread

thread2: thread2.c
	gcc thread2.c -o thread2 -lpthread

thread3: thread3.c
	gcc thread3.c -o thread3 -lpthread

thread4: thread4.c
	gcc thread4.c -o thread4 -lpthread

thread4a: thread4a.c
	gcc thread4a.c -o thread4a -lpthread

clean:
	rm -rf *.o
