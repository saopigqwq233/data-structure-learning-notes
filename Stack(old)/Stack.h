//栈的一些数据类型定义及操作
#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "stdlib.h"
#include "stdio.h"
//
//
//栈中数据类型
typedef int STElementType;
//栈的定义
typedef struct
{
    STElementType *base;//指向栈底元素的指针
    STElementType *top;//指向栈顶元素的指针
    int StackSize;//栈的容量多大
}Stack;
//关于栈的一些操作
void InitST(Stack *ST,int StackSize);//初始化ST指向的一个容量为capacit的栈
void DestroyST(Stack*ST);//销毁ST栈
int STIsEmpty(Stack*ST);//判断是空栈,是返回1，不是返回0
int STIsFull(Stack*ST);//判断栈满不满，满返回1，不满返回0
void STlength(Stack*ST);//求栈有多少个元素
void ClearST(Stack*ST);//删除栈中所有元素
void PushST(Stack *ST,STElementType num);//入栈操作
void PopST(Stack *ST);//将ST所指的栈进行出栈
STElementType TopST(Stack *ST);//求ST所指栈的栈顶元素
#endif //STACK_STACK_H
