#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
//队列初始化，包括分配内存
Stack *Sinit(void)
{
    Stack *stack = (Stack *)malloc(sizeof(stack));
    memset(stack, 0, sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;    
}

void Sfree(Stack *stack)
{
   if (stack == NULL) {
        return;
   }
   if(stack->size == 0){
        free(stack);
	return;
   }
   Snode *temp_node = stack->top;
   while(temp_node != NULL) {
	Snode *free_node = temp_node;
	temp_node = temp_node->next;
	free(free_node);
   }
   free(stack);
}
void Spush(Stack *stack, int val)
{
     Snode *temp_node = (Snode *)malloc(sizeof(Snode));
     memset(temp_node, 0, sizeof(Snode));
     temp_node->val = val;
     if (stack->top == NULL) {
         stack->top = temp_node;
     } else {
	 temp_node->next = stack->top;
         stack->top = temp_node;
     }
     stack->size++;
}
int Spop(Stack *stack)
{
    if(stack->size == 0) {
        printf("This stack is empty!");
	return 0;
    }
    Snode *temp_node = stack->top;
    stack->top = temp_node->next;
    int temp_data = temp_node->val;
    stack->size--;
    free(temp_node);
    return temp_data;
}
bool Sexist(Stack *stack, int val) 
{
    if (stack->top == NULL) {
	return false;
    }
    Snode *temp_node = stack->top;
    while(temp_node != NULL) {
        if (temp_node->val == val) {
	     return true;
	}
	temp_node = temp_node->next;
    }
    return false;
}
int Stop(Stack *stack)
{
   if (stack->size == 0) {
       printf("This stack is empty!");
       return 0;
   }
   return stack->top->val;
}
int Ssize(Stack *stack)
{
   return stack->size;
}
bool Sempty(Stack *stack)
{
    return stack->size == 0 ? true:false; 
}

