#include "pre.h"
void InsertSort(int *a,int n)
{
    //升序
    //从第二个数开始遍历数组
    //1.end=i-1,需要把第i个数tmp=a[i]插入到前（包括）end下标的数里面
    //2.与a[end]比较，如果a[end]>tmp,则把a[end]后移，end--
    //3.当遇到a[end]<=tmp,a[end]停止后移，a[end+1]=tmp;
    //4.循环条件控制end>=0----》所有的数均大于tmp，end=-1,则a[end+1]=tmp
    //5.如果a[end]均小于tmp，那么a[end+1]=tmp
    int times=0;

    for (int i = 1; i < n; ++i)
    {
        int end=i-1;
        int tmp=a[i];

        while (end>=0)
        {
            times++;
            if(a[end]>tmp)
            {
                a[end+1]=a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end+1]=tmp;
    }
    printf("InsertSort:%d\n",times);
}