#include "pre.h"

int main()
{
    int a[]={100,928,32,133,133,53,24,28,183,854,266,6,12,432,120,28};
    int b[16];
    int c[16];
    int d[16];
    memcpy(b,a,sizeof (a));
    memcpy(c,a,sizeof (a));
    memcpy(d,a,sizeof (a));
    int size=sizeof (a)/sizeof(int );
    printf("Ô­Êý×é£º");
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

    return 0;
}
