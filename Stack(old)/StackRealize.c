#include "Stack.h"
void InitST(Stack *ST,int StackSize)
{
    ST=(Stack*) malloc(sizeof (Stack));//申请一块Stack类型的空间
    if(ST)//如果ST申请失败
    {
        printf("栈初始化失败\n");
        return;
    }
    else
    {
        ST->base = (STElementType *) malloc(sizeof(STElementType) * StackSize);//空间中
        // 栈底base申请一块StackSize大小的数组
        if(ST->base)//如果栈存储区申请失败
        {
            printf("栈存储区初始化失败\n");
            free(ST);
            return;
        }
        else
        {
            ST->top = ST->base;//先将top与base相等
            ST->StackSize = StackSize;//将栈容量确定
            printf("栈初始化成功\n");
        }
    }
}
int STIsEmpty(Stack*ST)//判断是空栈,是返回1，不是返回0
{
    if(ST->top==ST->base)
        return 1;
    else
        return 0;
}
int STIsFull(Stack*ST)
{
    if(ST->top-ST->base==ST->StackSize)
        return 1;
    else
        return 0;
}
void PushST(Stack *ST,STElementType num)//入栈操作
{
    if(STIsFull(ST))//如果栈满，则退出
    {
        printf("栈满，无法继续入栈\n");
        return;
    }
    else
    {
        *(ST->top)=num;
        ST->top++;//赋值完成后，top指向栈的下一个空间
    }
}
void DestroyST(Stack*ST)//销毁ST栈
{

}