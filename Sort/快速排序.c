#include "pre.h"
void Swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void QuickSort(int *a,int left,int right)
{
    if(left>=right)//数组长度为1或0，已是排好序的状态
        return;

    int pivot= PartSort2(a,left,right);//选取范围的pivot并把小于[pivot]的元素放左面，大于的在pivot右面
    QuickSort(a,left,pivot-1);
    QuickSort(a,pivot+1,right);
}
int PartSort1(int* a, int left, int right)
{
    int key=left;
    //right向左遍历，left向右遍历，两者相遇时停下
    //right先遍历，当[right]<[key]，right暂停
    //left后遍历，当[left]>[key],left暂停
    //[left],[right]互换
    //因为是right先找到比[key]小的数，left和right相遇的元素<[key]
    //[left or right] 和[key]互换
    while (left!=right)
    {
        while (right!=left&&a[right]>=a[key])
            right--;
        while (left!=right&&a[left]<=a[key])
            left++;

        Swap(&a[left],&a[right]);
    }
    Swap(&a[key],&a[left]);
    return left;
}


int PartSort2(int* a, int left, int right)
{
    int pivot = (left+right)/2;
    //设置一个hole坑，并把[hole]的值key提取出来
    //right先左移找到小于key值的[right]
    //[right]换到坑中
    //left右移找到大于key值的[left]
    //[left]换到坑中
    //left和right相遇，由于[right]此时是小于key的
    Swap(&a[left],&a[pivot]);

    int key=a[left];
    int hole=left;
    while (left<right)
    {
        while (left<right&&a[right]>=key)
        {
            right--;
        }
        a[hole]=a[right];
        hole=right;
        while (left<right&&a[left]<=key)
        {
            left++;
        }
        a[hole]=a[left];
        hole=left;
    }
    //left此时==right==hole
    a[hole]=key;
    return hole;
}


int PartSort3(int* a, int left, int right)
{
    int pivot=(left+right)/2;

    //把[pivot]换到最右面
    Swap(&a[right],&a[pivot]);

    //设置i=left,j=left,j变量遍历left-right
    //当遇到[j]<[right]，就让[i]和[j]互换,并让i加1
    //因此，[left]到[i-1]全是小于[right]的
    //[i]到[j-1]的全是大于[right]的
    //[j]到[right-1]的还未知大小
    //j遍历完后，[i]一定大于[right],[i]和[right]互换
    int i=left;int j=left;
    while (j<right)
    {
        if(a[j]<a[right])
        {
            Swap(&a[i],&a[j]);
            i++;
        }
        j++;
    }
    Swap(&a[right],&a[i]);
    return i;
}

