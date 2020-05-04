/*
Description:使用C语言实现优先队列;
CEATOR：yaoqinchuan
2020-05-02
 */
#include <stdbool.h>
typedef struct data
{
   int val;
   int pri;
}data;
typedef struct Pqnode
{
    data val;
    struct Pqnode *next;
}Pqnode;

typedef struct Pqueue
{
    struct Pqnode *front;
    struct Pqnode *tail;
    int size;
}Pqueue;

// 队列初始化
extern Pqueue *Pqinit(void);
// 队列销毁
extern void Pqdestory(Pqueue *pqueue);
// 队列加入元素
extern void Pqpush(Pqueue *pqueue,data val);
// 队列弹出
extern data Pqpop(Pqueue *pqueue);
// 返回队列第一个元素
extern data Pqfront(Pqueue *queue);
// 返回队列大小
extern int Pqsize(Pqueue *queue);
// 返回队列是否为空
extern bool Pqempty(Pqueue *queue);
