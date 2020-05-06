#include <stdio.h>
#include "util/queue.h"
#include "util/stack.h"
//图的连接情况
char graph[][5] = {
   {'A','B','C','0','0'},
   {'B','A','C','D','0'},
   {'C','A','D','E','0'},
   {'D','B','E','F','0'},
   {'E','C','D','0','0'},
   {'F','D','0','0','0'},
};
bool if_need_push_queue(Stack *stack, Queue *output, int elem)
{
    if (Qexist(output, elem) == true) {
        return false;
    }
    if (Sexist(stack, elem) == true) {
        return false;
    }
    return true;
}
void dfs(void)
{
    Stack *queue = Sinit();
    Queue *output = Qinit();
    Spush(queue, 'A'-'A');// 压入第一个元素，起点
    while(queue->size != 0) {
	int elem = Spop(queue);
	Qpush(output, elem);// 输出的队列
        int j = 1;
	while(graph[elem][j] != '0') {
	    if (if_need_push_queue(queue, output, graph[elem][j] - 'A')) {
	    	Spush(queue, graph[elem][j] - 'A');
	    }
	    j++;
	}
    }
    while (output->front != NULL){
        printf("%c \r\n",'A' + Qpop(output));
    }
    Sfree(queue);
    Qfree(output);
    return;
}
int main ()
{
    dfs();
    printf("hello DFS\r\n");
}
