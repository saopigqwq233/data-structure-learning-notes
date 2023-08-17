#include "Queue.h"
void QueueInit(Queue* pq)//队列初始化
{
    assert(pq);
    pq->phead=null;
    pq->ptail=null;
    pq->size=0;
}
void QueueDestroy(Queue* pq)//队列销毁
{
    assert(pq);
    QueueNode *cur=pq->phead;
    while (cur)//指针cur和next遍历队列，当cur到null时说明到队尾
    {
        QueueNode *next=cur->next;
        free(cur);
        cur=next;
    }
    //队列置空
    pq->phead=pq->ptail=null;
    pq->size=0;
}

void QueuePush(Queue* pq,QDatatype x)//入队尾
{
    assert(pq);
    QueueNode *newNode=(QueueNode*) malloc(sizeof (QueueNode));
    if(newNode==null)//malloc失败
    {
        perror("malloc error\n");
        return;
    }
    //创建新节点
    newNode->data=x;
    newNode->next=null;

    //加入链式结构
    if(pq->phead==NULL)
    {
        pq->phead=pq->ptail=newNode;
    }
    else
    {
        pq->ptail->next=newNode;//将新节点接入队尾
        pq->ptail=newNode;//刷新尾节点
    }
    pq->size++;
}
void QueuePop(Queue* pq)//出队头
{
    assert(pq);
    assert(!QueueEmpty(pq));

    //为了避免队列只有一个节点，出队后，phead和ptail变成野指针，需要将phead和ptail置空
    //1.一个节点
    if(pq->phead->next==null)
    {
        free(pq->phead);
        pq->phead=pq->ptail=null;
    }
    //2.两个节点
    else
    {
        QueueNode *tmp=pq->phead->next;
        free(pq->phead);
        pq->phead=tmp;
    }

    //队规模-1
    pq->size--;
}

QDatatype QueueFront(Queue* pq)//队头元素
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->phead->data;
}
QDatatype QueueBack(Queue* pq)//队尾元素
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->ptail->data;
}
int QueueSize(Queue* pq)//队长度
{
    assert(pq);
    return pq->size;
}
bool QueueEmpty(Queue*pq)//队空
{
    assert(pq);

    return pq->size==0;
}

void QPrint(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    QueueNode *cur=pq->phead;
    while (cur)
    {
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("\n");
}
