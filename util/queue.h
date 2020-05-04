/*
Description:使用C语言实现队列;
CEATOR：yaoqinchuan
2020-05-02
 */
#include <stdbool.h>
typedef struct Qnode
{
    int val;
    struct Qnode *next;
}Qnode;

typedef struct Queue
{
    struct Qnode *front;
    struct Qnode *tail;
    int size;
}Queue;

// 队列初始化
extern Queue *Qinit(void);
// 队列销毁
extern void Qdestory(Queue *queue);
// 队列加入元素
extern void Qpush(Queue *queue, int val);
// 队列弹出
extern int Qpop(Queue *queue);
// 返回队列第一个元素
extern int Qfront(Queue *queue);
// 返回队列大小
extern int Qsize(Queue *queue);
// 返回队列是否为空
extern bool Qempty(Queue *queue);
