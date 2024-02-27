#include "iostream"
#include "random"
using namespace std;
int partition(int*a,int start_index,int end_index){
//    选择第一个元素作为pivot
    int pivot = a[start_index];
//    左右两个索引
    int left = start_index;
    int right = end_index;
    while (left<right){
//        右指针先移动
        while (left<right){
            if(a[right]<pivot) {
                a[left] = a[right];
                break;
            }
            else
                right--;
        }
        while (left<right){
            if(a[left]>pivot){
                a[right] = a[left];
                break;
            }
            else
                left++;
        }
    }
    a[left] = pivot;
    return left;
}
void QuickSort_v1(int *a,int start_index,int end_index){
    if(start_index>end_index)
        return;
    int pivot_index = partition(a,start_index,end_index);
    QuickSort_v1(a,start_index,pivot_index-1);
    QuickSort_v1(a,pivot_index+1,end_index);
}
int main()
{
    const int bb =2;
    srand(3);
    int a[bb];
    for (int i = 0; i < bb; ++i) {
        a[i] = rand()%100;
    }
    for(auto i:a){
        cout<<i<<' ';
    }
    cout<<endl;
    QuickSort_v1(a,0,bb-1);
    for(auto i:a){
        cout<<i<<' ';
    }
    cout<<endl;
}
