#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "util/queue.h"
#include "util/stack.h"
#include "util/pri_queue.h"
int main ()
{
   Pqueue *pqueue = Pqinit();
   Queue *queue = Qinit();
   Stack *stack = Sinit();
   for (int i = 0; i < 10; i++) {
       Qpush(queue, i);
       Spush(stack, i);
       data temp_pqdata = {0};
       temp_pqdata.val = i;
       temp_pqdata.pri = 10 - i;
       Pqpush(pqueue, temp_pqdata);
       printf("queue size is %d\r\n", Qsize(queue));
       printf("stack size is %d\r\n", Ssize(stack));
       printf("Pri queue size is %d\r\n",Pqsize(pqueue));
   }
   int qsize = Qsize(queue);
   for (int j = 0; j < qsize; j++) {
       printf("Queue %d number is %d \r\n", j, Qpop(queue));
       printf("Stack %d number is %d \r\n", j, Spop(stack));
       data p_temp = Pqpop(pqueue);
       printf("Pri queue %d pri is %d  val is %d\r\n", j, p_temp.pri,
              p_temp.val);
   }
   printf("queue size is %d\r\n",Qsize(queue));
   printf("stack size is %d\r\n",Ssize(stack));
   printf("Pqueue size id %d\r\n", Pqsize(pqueue));
   printf("end!\r\n");
}
