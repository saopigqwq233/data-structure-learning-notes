#include "Heap.h"
int main()
{
/*    HP hp;
    HPInint(&hp);*/
    int arr[]={10,20,33,23,76,18,34,87};
   /* for (int i = 0; i < sizeof (arr)/sizeof (int ); ++i)
    {
        HPPush(&hp,arr[i]);
    }
    while (!HPEmpty(&hp))
    {
        int top= HPTop(&hp);
        printf("%d\n",top);
        HPPop(&hp);
    }*/
    HeapSort(arr,sizeof (arr)/sizeof (int ));
    for (int i = 0; i < sizeof (arr)/sizeof (int ); ++i)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
