#include "SeqQueue.h"
void InitQueue(SeqQueue*PSQ, int Length)
{
    PSQ->base=(QElementType*) malloc(sizeof (QElementType)*Length);//初始化队列空间
    if(PSQ->base==NULL)
    {
        printf("初始化失败\n");
        exit(1);
    }
    PSQ->Front= PSQ->Rear=0;//队头和队尾均指向队列第一个元素
    PSQ->QueueStorag=Length;
}
void EnterQueue(SeqQueue*PSQ,QElementType QElement)
{
    //上溢风险大
    /*PSQ->base[PSQ->Rear]=QElement;
    PSQ->Rear++;*/
    if(!QIsFull(PSQ))//队不满
    {
        PSQ->base[PSQ->Rear]=QElement;
        PSQ->Rear=(PSQ->Rear+1)%PSQ->QueueStorag;//通过取模运算
        // 可构成一个循环队列
    }
    else
    {
        printf("队已满\n");
        exit(1);
    }
}
QElementType DeQueue(SeqQueue*PSQ)
{
    if(!QIsEmpty(PSQ))//队列非空
    {
        QElementType ret=PSQ->base[PSQ->Front];
        PSQ->Front=(PSQ->Front+1)%PSQ->QueueStorag;
        return ret;
    }
    else
    {
        printf("队列为空\n");
        exit(1);
    }
}
int QIsFull(SeqQueue*PSQ)
{
    if((PSQ->Rear+1)%PSQ->QueueStorag==PSQ->Front)//队尾再来一个元素
        // ，队列就满了，我们特意空出这一个元素，默认此时已经满
        return True;
    else
        return False;
}
int QIsEmpty(SeqQueue*PSQ)
{
    if(PSQ->Front==PSQ->Rear)//队头下标等于队尾下标
        return True;
    else
        return False;
}
int LengthQueue(SeqQueue*PSQ)
{
    return (PSQ->Rear+PSQ->QueueStorag-PSQ->Front)%PSQ->QueueStorag;
}
void DestroyQueue(SeqQueue*PSQ)
{
    if(PSQ==NULL)//本来就没有队列空间
    {
        printf("无队列\n");
        exit(1);
    }
    else
    {
        free(PSQ->base);
        free(PSQ);
        PSQ = NULL;
    }
}
void ClearQueue(SeqQueue*PSQ)
{
    PSQ->Rear=PSQ->Front=0;
    for (int i = 0; i < PSQ->QueueStorag; ++i) //将队列每个元素赋值为0
    {
        PSQ->base[i]=(QElementType)0;
    }
}
QElementType GetQueueFront(SeqQueue*PSQ)
{
    return PSQ->base[PSQ->Front];
}