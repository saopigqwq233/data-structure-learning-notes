//队列遵循先进先出原则
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"
#define null NULL

typedef int QDatatype;
//队列节点
typedef struct QueueNode{
    QDatatype data;//队列数据
    struct QueueNode* next;
}QueueNode;
//队列
typedef struct Queue{
    QueueNode *phead;
    QueueNode *ptail;
    int size;
}Queue;

void QueueInit(Queue* pq);//队列初始化
void QueueDestroy(Queue* pq);//队列销毁

void QueuePush(Queue* pq,QDatatype x);//入队尾
void QueuePop(Queue* pq);//出队头

QDatatype QueueFront(Queue* pq);//队头元素
QDatatype QueueBack(Queue* pq);//队尾元素
int QueueSize(Queue* pq);//队长度
bool QueueEmpty(Queue*pq);//队空

void QPrint(Queue* pq);
#endif //QUEUE_QUEUE_H
