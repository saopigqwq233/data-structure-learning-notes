#include "iostream"

using namespace std;

void merge(int*a,int low,int mid,int high){
    int *b = new int [high-low+1];
    int i=low,j=mid+1,k=0;
    while (i<=mid&&j<=high){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        } else
            b[k++] = a[j++];

    }
    while (i<=mid)
        b[k++] = a[i++];
    while (j<=high)
        b[k++] = a[j++];
    k=0;
    for (int l = low; l <=high; ++l) {
        a[l] = b[k++];
    }
    delete []b;
}
void merge_sort(int*a,int low,int high){
    if(low==high)
        return;
    else {
        int mid = (low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge_sort(int a[],int n){
    int i,s;
    int t =1;
    while (t<n){
        s = t;
        t*=2;
        i=0;
        while (i+t<n){
            merge(a,i,i+s-1,i+s*2-1);
        }
        if(i+s<n){
            merge(a,i,i+s-1,n-1);
        }
    }
}
int main(){
    int n=10;
    srand(9);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand()%100;
    }
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    merge_sort(arr,n);
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}



