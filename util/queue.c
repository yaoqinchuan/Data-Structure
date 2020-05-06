#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
//队列初始化，包括分配内存
Queue *Qinit(void)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    memset(queue, 0, sizeof(Queue));
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;    
}

void Qfree(Queue *queue)
{
   if (queue == NULL) {
        return;
   }
   if(queue->size == 0){
        free(queue);
	return;
   }
   Qnode *temp_node = queue->front;
   while(temp_node != NULL) {
	Qnode *free_node = temp_node;
	temp_node = temp_node->next;
	free(free_node);
   }
   free(queue);
}
void Qpush(Queue *queue, int val)
{
     Qnode *temp_node = (Qnode *)malloc(sizeof(Qnode));
     memset(temp_node, 0, sizeof(Qnode));
     temp_node->val = val;
     if ((queue->tail == NULL) || (queue->front == NULL)) {
         queue->front = temp_node;
     } else {
         queue->tail->next = temp_node;
     }
     queue->tail = temp_node;
     queue->size++;
}
int Qpop(Queue *queue)
{
    if(queue->size == 0) {
        printf("This queue is empty!");
	return 0;
    }
    Qnode *temp_node = queue->front;
    int temp_data = temp_node->val;
    queue->front = queue->front->next;
    queue->size--;
    free(temp_node);
    return temp_data;
}
int Qfront(Queue *queue)
{
   if (queue->size == 0) {
       printf("This queue is empty!");
       return 0;
   }
   return queue->front->val;
}
int Qsize(Queue *queue)
{
   return queue->size;
}
bool Qexist(Queue *queue, int elem)
{
    if (queue->size == 0) {
        return false;
    }
    Qnode *temp_node = queue->front;
    while(temp_node != NULL) {
        if (temp_node->val == elem) {
	    return true;
	}
	temp_node = temp_node->next; 
    }
    return false;
}
bool Qempty(Queue *queue)
{
    return queue->size == 0 ? true:false; 
}

