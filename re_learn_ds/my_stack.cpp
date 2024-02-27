#include "iostream"
#include "cassert"
#include "cstdlib"
using namespace std;
#define DataType int
#define N 10
class my_stack{
private:
    DataType *_data;
    int _capacity;
    int _size;
    bool full()const{return _size ==_capacity;}
public:
    my_stack();
    my_stack(my_stack&s);
    ~my_stack();
    bool empty()const;
    int size()const;
    void push(DataType val);
    DataType top();
    void pop();
    void swap(my_stack&s);
    void Print();
};

my_stack::my_stack() {
    this->_data = (DataType*) malloc(N*sizeof(DataType));
    this->_capacity = N;
    this->_size = 0;
}

my_stack::my_stack(my_stack &s) {
    this->_size = s._size;
    this->_capacity = s._capacity;
    this->_data = (DataType*) malloc(s._capacity*sizeof(DataType));
    memcpy(this->_data,s._data,s._size*sizeof(DataType));
}

bool my_stack::empty() const {
    return _size == 0;
}

int my_stack::size() const {
    return _size;
}

void my_stack::push(int val) {
    if(full()){
        _data = (DataType*) realloc(_data,_capacity*2);
        _capacity*=2;
    }
    _data[_size] = val;
    _size++;
}

DataType my_stack::top() {
    if(empty()) {
        cout<<"no element in stack"<<endl;
        exit(1);
    }
    else{
        return _data[_size-1];
    }
}

void my_stack::pop() {
    if(empty()) {
        cout<<"no element in stack"<<endl;
        exit(1);
    }
    else
        _size--;
}

void my_stack::swap(my_stack &s) {
    DataType*tmp = s._data;
    s._data = this->_data;
    this->_data = tmp;

    int temp = this->_size;
    this->_size = s._size;
    s._size = temp;

    int t = this->_capacity;
    this->_capacity = s._capacity;
    s._capacity = t;
}

void my_stack::Print() {
    cout<<"---stack element---"<<endl;
    for (int i = 0; i < _size; ++i) {
        cout<<_data[i]<<' ';
    }
    cout<<endl<<"---end---"<<endl;
}

my_stack::~my_stack() {
    free(_data);
    _data = nullptr;
    _capacity = 0;
    _size = 0;
}

int main(){
    srand(2);

    my_stack s;
    for (int i = 0; i < 14; ++i) {
        s.push(rand()%100);
    }
    s.Print();

    my_stack b;
    for (int i = 0; i < 14; ++i) {
        b.push(rand()%100);
    }
    b.Print();
    s.swap(b);
    s.Print();
    cout<<s.top()<<endl;
    s.pop();
    s.Print();
    cout<<s.size()<<endl;
    return 0;
}
