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
    printf("ԭ���飺\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");


    
    printf("��������");
    InsertSort(a,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");



    printf("ϣ������");
    ShellSort(b,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",b[i]);
    }
    printf("\n");



    printf("ѡ������");
    SelectSort(c,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",c[i]);
    }
    printf("\n");


    printf("����������\n");
    HeapSort(d,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",d[i]);
    }
    printf("\n");

    printf("ð������");
    BubbleSort(e,size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",e[i]);
    }
    printf("\n");

    printf("��������\n");
    QuickSort(f,0,size-1);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",f[i]);
    }
    printf("\n");
    return 0;
}
