#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "stdbool.h"
#define null NULL

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
void AdjustDown(HP* obj,int size,int parent);

void Swap(HPDataType* a,HPDataType* b);

#endif //HEAP_HEAP_H

//桶排序
void HeapSort(int *a,int n);
