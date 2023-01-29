#ifndef LINKQUEUE_LINKQUEUE_H
#define LINKQUEUE_LINKQUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
//链队数据类型
typedef int LQElementType;
typedef struct Node{
    LQElementType Data;//链队数据
    struct Node* next;
}LinkQueueNode;
void InitLQueue(LinkQueueNode* )
#endif //LINKQUEUE_LINKQUEUE_H
