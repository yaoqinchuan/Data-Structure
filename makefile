dfs: queue.o stack.o dfs.o
#bfs: queue.o stack.o pri_queue.o bfs.o
dfs.o: util/queue.h util/stack.h dfs.c
	gcc -c dfs.c
bfs.o: util/queue.h bfs.c
	gcc -c bfs.c
queue.o: util/queue.h util/queue.c
	gcc -c util/queue.c
stack.o: util/stack.h util/stack.c
	gcc -c util/stack.c
pri_queue.o: util/pri_queue.h util/pri_queue.c
	gcc -c util/pri_queue.c
test.o: util/queue.h  util/stack.h util/pri_queue.h  test.c
	gcc -c test.c
clean:
	rm -rf queue.o stack.o test.o pri_queue.o bfs.o  dfs.o test bfs dfs
