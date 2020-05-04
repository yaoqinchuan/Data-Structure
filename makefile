test: test.o queue.o stack.o pri_queue.o
queue.o: util/queue.h util/queue.c
	gcc -c util/queue.c
stack.o: util/stack.h util/stack.c
	gcc -c util/stack.c
pri_queue.o: util/pri_queue.h util/pri_queue.c
	gcc -c util/pri_queue.c
test.o: util/queue.h  util/stack.h util/pri_queue.h  test.c
	gcc -c test.c
clean:
	rm -rf queue.o stack.o test.o pri_queue.o test
