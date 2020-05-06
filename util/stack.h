#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
typedef struct Snode
{
    struct Snode *next;
    int val;
}Snode;
typedef struct Stack
{
    struct Snode *top;
    int size;
}Stack;
// 栈初始化
extern Stack *Sinit(void);
// 栈销毁
extern void Sfree(Stack *stack);
// 压栈
extern void Spush(Stack *stack, int val);
// 弹栈
extern int Spop(Stack *stack); 
// 栈顶元素
extern int Stop(Stack *stack);
// 检查特定元素是否在栈中
extern bool Sexist(Stack *stack, int val);
// 栈大小 
extern int Ssize(Stack *stack);
// 检测栈是否为空
extern bool Sempty(Stack *stack);
#endif
