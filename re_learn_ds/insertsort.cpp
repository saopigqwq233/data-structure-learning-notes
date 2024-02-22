#include "iostream"
#include "cassert"
using namespace std;

void swap(int *a1,int *a2){
    int tmp = *a1;
    *a1=*a2;
    *a2=tmp;
}
//默认升序
void insert_sort(int* a,int n) {
    assert(a);
    int end_index = n - 1;
    for (int i = 1; i <= end_index; i++) {
        for (int tail = i - 1; tail >= 0; tail--)
            if (a[tail] > a[tail + 1])
                swap(&a[tail], &a[tail + 1]);
            else
                break;
    }
}
int main(){
    int a[10]={4,1,7,5,9,3,8,0,1,2};
    insert_sort(a,10);
    for(auto i:a){
        cout<<i<<' ';
    }
    return 0;
}
