#include <stdio.h>
#include "util/queue.h"
//图的连接情况
char graph[][5] = {
   {'A','B','C','0','0'},
   {'B','A','C','D','0'},
   {'C','A','D','E','0'},
   {'D','B','E','F','0'},
   {'E','C','D','0','0'},
   {'F','D','0','0','0'},
};
bool if_need_push_queue(Queue *queue, Queue *output, int elem)
{
    if (Qexist(output, elem) == true) {
        return false;
    }
    if (Qexist(queue, elem) == true) {
        return false;
    }
    return true;
}
void bfs(void)
{
    Queue *queue = Qinit();
    Queue *output = Qinit();
    Qpush(queue, 'A'-'A');// 压入第一个元素，起点
    while(queue->size != 0) {
	int elem = Qpop(queue);
	Qpush(output, elem);// 输出的队列
        int j = 1;
	while(graph[elem][j] != '0') {
	    if (if_need_push_queue(queue, output, graph[elem][j] - 'A')) {
	    	Qpush(queue, graph[elem][j] - 'A');
	    }
	    j++;
	}
    }
    while (output->front != NULL){
        printf("%c \r\n",'A' + Qpop(output));
    }
    Qfree(queue);
    Qfree(output);
    return;
}
int main ()
{
    bfs();
    printf("hello BFS\r\n");
}
