#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pri_queue.h"
//队列初始化，包括分配内存
Pqueue *Pqinit(void)
{
    Pqueue *queue = (Pqueue *)malloc(sizeof(Pqueue));
    memset(queue, 0, sizeof(Pqueue));
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;    
}

void Pqdestory(Pqueue *queue)
{
   if (queue == NULL) {
        return;
   }
   if(queue->size == 0){
        free(queue);
	return;
   }
   Pqnode *temp_node = queue->front;
   while(temp_node != NULL) {
	Pqnode *free_node = temp_node;
	temp_node = temp_node->next;
	free(free_node);
   }
   free(queue);
}
void insert_data_by_pri(Pqueue *queue, Pqnode *temp_node)
{
    Pqnode *cu_node = queue->front;
    if (cu_node->val.pri > temp_node->val.pri) {
        temp_node->next = cu_node;
       	queue->front = temp_node;
       	return;
    }
    while((cu_node->next != NULL) &&
           (cu_node->next->val.pri <= temp_node->val.pri)) {
	    cu_node = cu_node->next;
    }
    if (cu_node->next == NULL) {
        queue->tail->next = temp_node;
     } else {
	temp_node->next = cu_node->next;
	cu_node->next = temp_node;
     }
    return;
}
void Pqpush(Pqueue *queue, data val)
{
     Pqnode *temp_node = (Pqnode *)malloc(sizeof(Pqnode));
     memset(temp_node, 0, sizeof(Pqnode));
     temp_node->val = val;
     if (queue->tail == NULL) {
         queue->front = temp_node;
         queue->tail = temp_node;
     } else {
	 insert_data_by_pri(queue, temp_node);
     }
     queue->size++;
}
data Pqpop(Pqueue *queue)
{
    if(queue->size == 0) {
        printf("This queue is empty!");
	data temp_data = {0};
	return temp_data;
    }
    Pqnode *temp_node = queue->front;
    data temp_data = temp_node->val;
    queue->front = queue->front->next;
    queue->size--;
    free(temp_node);
    return temp_data;
}
data Pqfront(Pqueue *queue)
{
   if (queue->size == 0) {
       printf("This queue is empty!");
       data temp_data = {0};
       return temp_data;
   }
   return queue->front->val;
}
int Pqsize(Pqueue *queue)
{
   return queue->size;
}
bool Pqempty(Pqueue *queue)
{
    return queue->size == 0 ? true:false; 
}

