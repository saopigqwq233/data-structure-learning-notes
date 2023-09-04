#include "pre.h"
//n为数组大小
//升序
void ShellSort(int* a, int n)
{
    //设置gap希尔值
    //i+gap*j(<n)几个数组成一组，进行插入排序

    int times=0;
    //gap缩减循环到gap=1
    for (int gap = n/2; gap>=1 ; gap/=2)
    {
        //接下来是以gap为跨度的插入排序
        //第i个数作为end，tmp为end+gap的跨度，
        for (int i = 0; i < n-gap; ++i)
        {
            int end = i;
            int tmp = a[end+gap];
            while (end>=0)
            {
                times++;
                if(a[end]>tmp)
                {
                    a[end+gap]=a[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            a[end+gap]=tmp;
        }
    }
    printf("ShellSort:%d\n",times);
}





