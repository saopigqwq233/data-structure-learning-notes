#include <vector>
#include "iostream"
#define N 10
#define DType int
using namespace std;
void Arr_print(int*a,int n){
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
//建小堆->降序排序
void swap(DType*a,DType*b){
    DType tmp = *a;
    *a = *b;
    *b = tmp;
}
void AdjustUp(int*a,int child){
    int parent = (child-1)/2;
    while (child>0){
        if(a[child]<a[parent])
        {
            swap(a[child],a[parent]);
            child = parent;
            parent = (child-1)/2;
        }
        else
            break;
    }
}
void AdjustDown(int*a,int n,int parent){
    int child = parent*2+1;
    while (child<n)
    {
        if (child + 1 < n && a[child + 1] < a[child])
            child++;
        if (a[child] < a[parent])
        {
            swap(&a[child], &a[parent]);
            parent = child;
            child = parent*2+1;
        }
        else
            break;
    }
}
void HeapSort(int *a,int n){
//    建小堆
    for (int i = (n-2)/2; i >= 0; --i)
    {
        AdjustDown(a,n,i);
    }
    int end = n-1;
    while (end>0){
        swap(&a[end],&a[0]);
        AdjustDown(a,end,0);
        end--;
    }
}
int main(){
    srand(10);
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand()%100;
    }
    Arr_print(arr,N);
    HeapSort(arr,N);
    Arr_print(arr,N);
}