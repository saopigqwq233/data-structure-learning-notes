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
    free(obj);
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
    AdjustDwon(obj->a,obj->size-1);
}
void AdjustDwon(HPDataType* a, int child)
{
    //和父节点比较大小，如果小于父节点，则换位
    int parent = (child - 1) / 2;
    while (child>0)
    {
        //换位
        if(a[parent]>a[child])
        {
            HPDataType tmp=a[parent];
            a[parent]=a[child];
            a[child]=tmp;
        }
        //如果相等或者父节点比子节点小
        else
            break;
        //child和parent往上遍历检查
        child=parent;
        parent=(child-1)/2;
    }

}
