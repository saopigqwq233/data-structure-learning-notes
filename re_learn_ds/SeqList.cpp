#include "iostream"
#include "random"
using namespace std;
#define N 10
void Swap(int&a,int&b){
    int tmp = a;
    a = b;
    b = tmp;
}
class SeqList{
private:
    int *arr;
    int size;
    int capacity;
    void ExpandCapacity();
public:
//    构造函数
    SeqList(int capacity=N):capacity(capacity),size(0){
        arr = new int[capacity];
    }
    SeqList(const SeqList& s){
        arr = new int[s.capacity];
        size = s.size;
        capacity = s.size;
        for (int i = 0; i < size; ++i) {
            arr[i]=s.arr[i];
        }
    }
    SeqList(const int *a,int n){
        arr = new int[n];
        capacity = n;
        size = n;
        for (int i = 0; i < n; ++i) {
            arr[i] = a[i];
        }
    }
//    析构函数
    ~SeqList(){
        delete []arr;
        arr = nullptr;
        size=capacity=0;
        cout<<"des done"<<endl;
    }
    void SLDestroy();
    void SLPrint() const;
    bool SLisEmpty() const;
    bool SLisFull() const;
    void SLPushBack(int val);
    void SLInsert(int val,int index);
    int SLSearch(int val);
    void SLDelete(int index);
    void DeleteAllVal(int val);
};

void SeqList::SLDestroy() {
    delete arr;
    arr = nullptr;
    capacity = size = 0;
    cout<<"des done"<<endl;
}
void SeqList::SLPrint() const{
    cout<<"capacity:"<<capacity<<" size:"<<size<<endl;
    cout<<"items:"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

bool SeqList::SLisEmpty() const {
    return !size;
}

bool SeqList::SLisFull() const {
    return size==capacity;
}

void SeqList::SLPushBack(int val) {
    if(SLisFull())
        ExpandCapacity();
    arr[size] = val;
    size++;
}

void SeqList::ExpandCapacity() {
    int* temp = new int[capacity*2];
    for(int i=0;i<capacity;i++){
        temp[i] = arr[i];
    }
    arr = temp;
    capacity*=2;
}

void SeqList::SLInsert(int val, int index) {
    if(index==size)
        SLPushBack(val);
    else if(index<size)
    {
        for (int i = size; i >index ; --i) {
            arr[i]=arr[i-1];
        }
        arr[index] = val;
        size++;
    }
    else if(index>size)
    {
        cout<<"insert out of shuffer"<<endl;
        exit(1);
    }
}

int SeqList::SLSearch(int val) {
    int index = 0;
    for(;index<size;index++)
    {
        if(arr[index] == val)
            return index;
    }
    return -1;
}

void SeqList::SLDelete(int index) {
    if(index>=size)
    {
        cout<<"index not found"<<endl;
        exit(2);
    }
    for (int i = index; i < size-1; ++i)
    {
        arr[i] = arr[i+1];
    }
    size--;
}

void SeqList::DeleteAllVal(int val) {
    int forward=0,back=0;
    for(;back<size;back++){
//        交换元素
        if(arr[back] != val) {
            arr[forward] = arr[back];
            forward++;
        }
    }
    size = size - (back-forward);

}

int main(){
    srand(7);
    int array[20];
    for (int & i : array) {
        i = rand()%100;
    }
    SeqList slist(array,20);
    slist.SLPrint();

//    slist.SLInsert(30,30);
//    slist.SLPrint();
    slist.SLDelete(3);
    slist.SLPrint();
    slist.DeleteAllVal(44);
    slist.SLPrint();
    slist.DeleteAllVal(12);
    slist.SLPrint();
    return 0;
}
