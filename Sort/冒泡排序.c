#include "pre.h"
void BubbleSort(int* a, int n)
{
    int times=0;
    for (int i = n-1; i>0; --i)
    {
        bool Swaped=false;
        for (int j = 0; j < i; ++j)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                Swaped=true;
            }
            times++;
        }
        if(!Swaped)
            break;
    }
    printf("BubbleSort:%d\n",times);
}