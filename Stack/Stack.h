#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"
#define null NULL
typedef int STDatatype;
typedef struct Stack{
    STDatatype *a;
    int top;
    int capacity;
}ST;

void STinit(ST *pst);//初始化
void STDestroy(ST *pst);//销毁栈
void STPush(ST *pst,STDatatype x);//入栈
void STPop(ST *pst);//出栈
STDatatype STTop(ST *pst);//栈顶元素
bool STEmpty(ST *pst);//判断栈是否为空
int STSize(ST *pst);//栈大小

void STPrint(ST *pst);

#endif //STACK_STACK_H
