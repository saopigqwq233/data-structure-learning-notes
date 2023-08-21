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
        if(SmallHeap(a[parent],a[child]))//调整成小堆
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
void AdjustDown(HPDataType * a,int size,int parent)
{
    assert(a);
    int lesschild = parent * 2 + 1;//假设更小的是左儿子
    while (lesschild<size)
    {
        if (lesschild + 1 < size && a[lesschild] > a[lesschild + 1])//右儿子存在且更大
        {
            lesschild++;
        }
        if (SmallHeap(a[parent],a[lesschild]))
        {
            Swap(&a[parent], &a[lesschild]);
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

    AdjustDown(obj->a,obj->size,0);
}
void Swap(HPDataType* a,HPDataType* b)
{
    HPDataType tmp=*a;
    *a=*b;
    *b=tmp;
}
void HeapSort(int *a,int n)
{
    //n为数组a的数据个数
   //法一弊端：空间开销大，需要先拷贝一遍数据
    /*HP hp;
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

   /**法二：向上调整，模拟插入，
    *
    *
    * */
    //下标为0的数据假设已经插入，从下标为1开始，i遍历所有下标，模拟入堆
    for (int i = 1; i < n; ++i)
    {
        AdjustUp(a,i);
    }
    //建立的大堆，将根节点与最后的节点互换（最大数据移到最后），然后忽略最后的数据（最后叶子）
    //接下来向下调整二叉树
    //再取调整后的根节点与最后的数据互换（次大数据移到倒数第二）
    //以此类推
    //得到升序
    int end=n-1;
    while (end>0)
    {
        Swap(&a[0],&a[end]);
        AdjustDown(a,end,0);
        end--;
    }
}

void CreateNDate()
{
    // 造数据
    int n = 10000;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if (fin == NULL)
    {
        perror("fopen error");
        return;
    }

    for (size_t i = 0; i < n; ++i)
    {
        int x = rand() % 1000000;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

void PrintTok(int k)
{
    //1.先读取文件中前K个整数，建成小堆
    //2.再遍历剩余N-K个数，当第i个数大于堆顶数据，则入堆
    //3遍历结束，留下的堆就是由最大的K个数组成的
    FILE *fout= fopen("data.txt", "r");

    int *smallHeap=(int *) malloc(sizeof (int )*k);
    if(smallHeap==NULL)
    {
        perror("malloc error\n");
        return;
    }

    //建堆
    for (int i = 0; i < k; ++i)
    {
        fscanf(fout,"%d",&smallHeap[i]);
        AdjustUp(smallHeap,i);
    }

    //遍历
    int val;
    while (fscanf(fout,"%d",&val)!=EOF)
    {
        if(val>smallHeap[0])
        {
            Swap(&val, &smallHeap[0]);
            AdjustDown(smallHeap,k,0);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        printf("%d  ",smallHeap[i]);
    }
}