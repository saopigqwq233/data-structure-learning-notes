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
    printf("ԭ���飺");
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

    return 0;
}
