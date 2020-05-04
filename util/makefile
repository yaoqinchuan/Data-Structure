target:queue.o stack.o pri_queue.o
queue.o: queue.h queue.c
	gcc -c queue.c
stack.o: stack.h stack.c
	gcc -c stack.c
pri_queue.o: pri_queue.c pri_queue.h
	gcc -c pri_queue.c
clean:
	rm -rf queue.o stack.o pri_queue.o

