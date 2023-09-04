#include "pre.h"
void SelectSort(int* a, int n)
{
    int times=0;
    for (int i = 0; i < n; ++i)
    {


        int min_flag=i;
        for (int j = i+1; j <n ; ++j)
        {
            times++;
            if(a[min_flag]>a[j])
            {
                min_flag=j;
            }
        }


        if(i!=min_flag)
        {
            int tmp=a[i];
            a[i]=a[min_flag];
            a[min_flag]=tmp;
        }
    }
    printf("SelectSort:%d\n",times);
}