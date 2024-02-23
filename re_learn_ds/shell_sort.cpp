#include "iostream"
#include "cassert"
#include "cstdlib"
using namespace std;
void swap(int*a,int*b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void shell_sort(int *a,int n){
    assert(a);
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            for(int j=1;i-j*gap>-1;j++){
                if(a[i-(j-1)*gap]<a[i-j*gap])
                    swap(&a[i-(j-1)*gap],&a[i-j*gap]);
            }
        }
    }
}

int main(){
    srand(8);
    int a[100];
    for (int i = 0; i < 100; ++i) {
        a[i]=rand()%100;
    }
    for(auto i:a)
        cout<<i<<' ';
    cout<<endl<<"sorted:";
    shell_sort(a,100);
    for(auto i:a)
        cout<<i<<' ';
    return 0;
}