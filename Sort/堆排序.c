#include "pre.h"
void AdjustDwon(int* a, int n, int root)
{
    int child=root*2+1;//假定是左叶子更大
    while(child<n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            child++;
        }

        if (a[child] > a[root])
        {
            Swap(&a[child], &a[root]);
            root = child;
            child = root * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int* a, int n)
{
//建大堆->反转重排
//反转时,不断递减最后一个树叶的下标
//根与最后的叶调换，再重排
//达到升序的效果

    //建大堆
    for (int i = (n-2)/2; i >=0; --i)
    {
        AdjustDwon(a,n,i);
    }

    int end=n-1;
    while (end>0)
    {
        Swap(&a[0],&a[end]);
        AdjustDwon(a,end,0);
        end--;
    }
}
