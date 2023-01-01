#ifndef LINKLIST_LIBRARY_H
#define LINKLIST_LIBRARY_H
typedef int ELEMENTTYPE;
typedef struct L{
    ELEMENTTYPE ELEMENTDATA;
    struct L*next;
}Link;
typedef Link* Positin;
Link *LINKLink(Positin R1,Positin R2);//链接两个循环链表
int Length_SinLink(Link*h);//求单链表长度
int Length_DulLink(Link*h);//求循环链表长度
//双向链表
typedef struct LL{
    ELEMENTTYPE ELEMENT;
    struct LL* next,*prior;
}Dub_Link;
void delete_Dub(Dub_Link*h,ELEMENTTYPE target);//删除双向链表的目标元素
#endif //LINKLIST_LIBRARY_H
