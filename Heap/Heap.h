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
void AdjustDwon(HPDataType* a, int child);//调整小堆
#endif //HEAP_HEAP_H
