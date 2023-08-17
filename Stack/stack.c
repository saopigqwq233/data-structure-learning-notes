#include "Stack.h"
void STinit(ST *pst)//初始化
{
    assert(pst);
    pst->a=null;
    pst->top=0;//top指向0说明栈为空
    pst->capacity=0;
}
void STDestroy(ST *pst)//销毁栈
{
    assert(pst);
    //释放栈空间并置空
    free(pst->a);
    pst->a=null;
    //top与capacity置0
    pst->capacity=pst->top=0;
}
void STPush(ST *pst,STDatatype x)//入栈
{
    //先判断栈是否满，满则扩容
    if(pst->top==pst->capacity)
    {
        int newcapacity=(pst->capacity==0)?4:(pst->capacity*2);//如果栈空间还未分配，则初始化4个空间
        STDatatype* tmp=(STDatatype*) realloc(pst->a,newcapacity*sizeof (STDatatype));
        //检查空间申请是否成功
        if(tmp==NULL)
        {
            perror("realloc error");
            return;

        }
        pst->a=tmp;
        pst->capacity=newcapacity;
    }
    //入栈操作
    pst->a[pst->top] = x;
    pst->top++;
}
void STPop(ST *pst)//出栈
{
    assert(pst);
    //判断是否为空
    assert(!STEmpty(pst));
    //直接把索引前移动
    pst->top--;
}
STDatatype STTop(ST *pst)//栈顶元素
{
    assert(pst);
    assert(!STEmpty(pst));
    return pst->a[pst->top-1];
}
bool STEmpty(ST *pst)//判断栈是否为空
{
    assert(pst);

    //如果为空返回1，不为空返回0
    //top为0则栈空
    return pst->top==0;
}
int STSize(ST *pst)//栈大小
{
    assert(pst);
    return pst->top;
}
void STPrint(ST *pst)
{
    assert(pst);
    assert(!STEmpty(pst));
    int tmp=0;
    int max=pst->top;
    while (tmp<max)
    {
        printf("%d->",pst->a[tmp]);
        tmp++;
    }
    printf("\n");
}