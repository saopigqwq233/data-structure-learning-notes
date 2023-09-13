#include "pre.h"
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

        int tmp=a[left];
        a[left]=a[right];
        a[right]=tmp;
    }
    int tmp=a[key];
    a[key]=a[left];
    a[left]=tmp;
    return left;
}

int PartSort2(int* a, int left, int right)
{
    int pivot=(left+right)/2;

    //把[pivot]换到最右面
    int tmp=a[right];
    a[right]=a[pivot];
    a[pivot]=tmp;

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
            int var=a[j];
            a[j]=a[i];
            a[i]=var;
            i++;
        }
        j++;
    }
    int var=a[right];
    a[right]=a[i];
    a[i]=var;
    return i;
}

int PartSort3(int* a, int left, int right)
{

}