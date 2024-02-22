#include "iostream"
#include <cassert>
using namespace std;
//升序
//后一个和前一个比,两两比较，大的往后放
void Swap(int*a,int *b){
    int tmp=*b;
    *b=*a;
    *a=tmp;
}
void BubbleSort(int * arr,int n){
    assert(arr);
    for(int EndIndex=n-1;EndIndex>0;EndIndex--)
    {
        for(int i=1;i<=EndIndex;i++)
        {
            if(arr[i-1]>arr[i])
                Swap(arr+i-1,arr+i);
            else
                continue;
        }
    }
}
int main(){
    int arr[10]={2,5,1,9,4,3,6,0,8,7};
    BubbleSort(arr,10);
    for (int i : arr) {
        cout<<i<<endl;
    }
    return 0;
}