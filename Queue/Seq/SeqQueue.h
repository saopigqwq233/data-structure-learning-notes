#ifndef SEQ_SEQQUEUE_H
#define SEQ_SEQQUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#define True 1
#define False 0
//数据结构声明
typedef int QElementType;
typedef struct {
    QElementType *base;//
    int Front;//队头
    int Rear;//队尾
    int QueueStorag;//队列容量
}SeqQueue;
//初始化队列
void InitQueue(SeqQueue*, int );//以指向顺序队列指针和队长为参数
//队列实际长度比初始化中的参数要小一个，后面会在判断队满时用到这少的一个
//销毁队列
void DestroyQueue(SeqQueue*);//以指向顺序队列的指针为参数
//清空队列
void ClearQueue(SeqQueue*);//以指向顺序队列的指针为参数
//队长
int LengthQueue(SeqQueue*);//以指向顺序队列的指针为参数,返回队长
//获得队头
QElementType GetQueueFront(SeqQueue*);//以指向顺序队列的指针为参数，返回队头数据
//入队
void EnterQueue(SeqQueue*,QElementType);//以指向顺序队列的指针和队列数据为参数
//出队
QElementType DeQueue(SeqQueue*);//以指向顺序队列的指针为参数，返回队列队尾元素
//队满
int QIsFull(SeqQueue*);//以指向顺序队列的指针为参数,返回0或者1
//队空
int QIsEmpty(SeqQueue*);//以指向顺序队列的指针为参数,返回0或者1
#endif //SEQ_SEQQUEUE_H
