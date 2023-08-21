#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "stdbool.h"
#include "time.h"
#define null NULL
//大堆排升序
#define BigHeap(Parent,Son) ((Parent)<(Son))
//小堆排降序
#define SmallHeap(Parent,Son) ((Parent)>(Son))
typedef int HPDataType;
typedef struct Heap{
    HPDataType *a;
    int size;
    int capacity;
}HP;
void HPInint(HP* obj);
void HPDestroy(HP* obj);
void HPPush(HP* obj,HPDataType value);
bool HPEmpty(HP* obj);

HPDataType HPTop(HP* obj);
void HPPop(HP* obj);


void AdjustUp(HPDataType* a,int child);//调整成大堆
void AdjustDown(HPDataType * a,int size,int parent);

void Swap(HPDataType* a,HPDataType* b);

#endif //HEAP_HEAP_H

//桶排序
void HeapSort(int *a,int n);
void CreateNDate();
//输出
void PrintTok(int k);
