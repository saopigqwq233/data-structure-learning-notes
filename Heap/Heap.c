#include "Heap.h"
void HPInint(HP* obj)
{
    assert(obj);
    obj->a=null;
    obj->size= obj->capacity=0;
}
void HPDestroy(HP* obj)
{
    assert(obj);
    free(obj->a);
    obj->a=null;
    obj->size=obj->capacity=0;
}
void HPPush(HP* obj,HPDataType value)
{
    assert(obj);
    //空间不够开空间
    if(obj->size==obj->capacity)
    {
        int newcapacity=(obj->capacity==0)?4:(obj->capacity*2);
        HPDataType* newheap=(HPDataType*) realloc(obj->a,sizeof (HPDataType)*newcapacity);
        if(newheap==null)
        {
            perror("realloc error");
            return;
        }
        obj->a=newheap;
        obj->capacity=newcapacity;
    }
    obj->a[obj->size]=value;
    obj->size++;
    //放入数组空间后调整使之符合堆
    AdjustUp(obj->a,obj->size-1);
}

void AdjustUp(HPDataType* a,int child)
{
    int parent=(child-1)/2;
    while (child>0)
    {
        if(a[parent]<a[child])//调整成大堆
        {
            Swap(&a[child],&a[parent]);
            child=parent;
            parent=(child-1)/2;
        }
        else
            break;

    }

}
bool HPEmpty(HP* obj)
{
    assert(obj);
    return obj->size==0;
}
void AdjustDown(HP* obj,int size,int parent)
{
    assert(obj);
    int lesschild = parent * 2 + 1;//假设更小的是左儿子
    while (lesschild<size)
    {
        if (lesschild + 1 < size && obj->a[lesschild] < obj->a[lesschild + 1])//右儿子存在且更小
        {
            lesschild++;
        }
        if (obj->a[parent] < obj->a[lesschild])
        {
            Swap(&obj->a[parent], &obj->a[lesschild]);
            parent = lesschild;
            lesschild = parent * 2 + 1;
        }
        else
            break;

    }
}
HPDataType HPTop(HP* obj)
{
    assert(obj);
    assert(!HPEmpty(obj));
    return obj->a[0];
}
void HPPop(HP* obj)
{
    assert(obj);
    assert(!HPEmpty(obj));

    Swap(&obj->a[0],&obj->a[obj->size-1]);
    obj->size--;

    AdjustDown(obj,obj->size,0);
}
void Swap(HPDataType* a,HPDataType* b)
{
    HPDataType tmp=*a;
    *a=*b;
    *b=tmp;
}
void HeapSort(int *a,int n)
{
   /* 法一弊端：空间开销大，需要先拷贝一遍数据
    *
    * HP hp;
    HPInint(&hp);
    for (int i = 0; i < n; ++i)
    {
        HPPush(&hp,a[i]);
    }
    int i=0;
    while (!HPEmpty(&hp))
    {
        int top= HPTop(&hp);
        a[i]=top;
        i++;
        HPPop(&hp);
    }
    HPDestroy(&hp);*/

   /**法二：向上调整
    * /
}