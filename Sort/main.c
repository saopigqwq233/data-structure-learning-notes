#include "pre.h"

int main()
{
    int a[]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    srand(time(NULL));
    for (int i = 0; i < 16; ++i)
    {
        a[i]=rand()%100;
    }
    int b[16];
    int c[16];
    int d[16];
    int e[16];
    int f[16];
    memcpy(b,a,sizeof (a));
    memcpy(c,a,sizeof (a));
    memcpy(d,a,sizeof (a));
    memcpy(e,a,sizeof (a));
    memcpy(f,a,sizeof (a));
    int size=sizeof (a)/sizeof(int );
    printf("Ô­Êý×é£º\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");


    
    printf("²åÈëÅÅÐò£º");
    InsertSort(a,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");



    printf("Ï£¶ûÅÅÐò£º");
    ShellSort(b,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",b[i]);
    }
    printf("\n");



    printf("Ñ¡ÔñÅÅÐò£º");
    SelectSort(c,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",c[i]);
    }
    printf("\n");


    printf("¶ÑÅÅÐòÅÅÐò£º\n");
    HeapSort(d,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",d[i]);
    }
    printf("\n");

    printf("Ã°ÅÝÅÅÐò£º");
    BubbleSort(e,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",e[i]);
    }
    printf("\n");

    printf("¿ìËÙÅÅÐò£º\n");
    QuickSort(f,0,size-1);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",f[i]);
    }
    printf("\n");
    return 0;
}
