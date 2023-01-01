#include "library.h"
#include "stdlib.h"
#include <stdio.h>
//链接两个循环链表
Link *LINKLink(Positin R1,Positin R2)
{
    Positin p=R1->next;//存表1表头
    R1->next=R2->next->next;//将表2的第一个元素链接到表1尾部
    free(R2->next);//删除表2表头
    R2->next=p;//将表2尾部接到表1表头
    return p;
}
//求单链表长度
int Length_SinLink(Link*h)
{
    int length=0;
    for(h=h->next;h!=NULL;h=h->next)
    {
        length++;
    }
    return length;
}
//求循环链表长度
int Length_DulLink(Link*h)
{
    Positin p=h->next;
    int length=0;
    for(;p!=h;p=p->next)
    {
        length++;
    }
    return 0;
}
void delete_Dub(Dub_Link*h,ELEMENTTYPE target)//删除双向链表的目标元素
{
    Dub_Link *p=h->next;
    for(;p!=NULL;p=p->next)
    {
        if(p->ELEMENT==target)
        {
            p->prior->next=p->next;
            p->next->prior=p->prior;
            free(p);
            break;
        }
    }
}