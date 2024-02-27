#include "iostream"
#include "random"
using namespace std;
void Swap(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int FindMin(int *a,int f_index,int e_index){
    int min_index = f_index;
    for (int i = f_index; i <= e_index; ++i) {
        if(a[i]<a[min_index])
            min_index = i;
    }
    return min_index;
}
void SelectionSort(int *a,int n){
//    遍历数组

//最小的元素放到最前面
    for (int i = 0; i < n; ++i){
        int min_index = FindMin(a,i,n-1);
        Swap(&a[min_index],&a[i]);
    }
}
int main(){
    int a[10];
    srand(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = rand()%100;
    }
    for(auto i:a)
        cout<<i<<' ';
    cout<<endl;
    SelectionSort(a,10);
    for(auto i:a)
        cout<<i<<' ';
}
