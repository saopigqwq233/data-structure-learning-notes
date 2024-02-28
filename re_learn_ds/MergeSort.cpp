#include "iostream"
#include "vector"
using namespace std;

int* merge(int* aB,int* aE,int* bB,int* bE){
    int *tmp = new int[aE-aB+(aE-aB)+2];
    int *i = tmp;
    while (aB!=aE&&bB!=bE){
        if(*aB<*bB)
            *i = *aB;
        else
            *i = *bB;
        i++;
    }
    for(;aB!=(aE+1);aB++,i++) *i = *aB;
    for(;bB!=(bE+1);bB++,i++) *i = *bB;
    return tmp;
}
void merge_sort(int *a,int b_index,int e_index){

}
void my_mergesort(int *a,int n){
    int left = 0,right = n-1;
    merge_sort(a,left,right);
}
int main(){
    int a[10];
    srand(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = rand()%100;
    }
    cout<<"1"<<endl;
    my_mergesort(a,10);
    for (int i = 0; i < 10; ++i) {
        cout<<a[i]<<' ';
    }
}






