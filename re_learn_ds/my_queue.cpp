#include "iostream"
#include "cstdlib"
#define QueueDType int
#define N 10
using namespace std;
//1链栈
class my_queue_1{
private:
    struct QueueNode{
        QueueDType data;
        QueueNode*next;
    };
    QueueNode*phead;
    QueueNode*ptail;
    int _size;
public:
    my_queue_1();
    my_queue_1(const my_queue_1&q);
    bool empty()const;
    int size()const;
    QueueDType front()const;
    QueueDType back()const;
    void push(QueueDType val);
    void pop();
    void swap(my_queue_1&q);

    void Print(){
        cout<<"---Queue---"<<endl;
        for(QueueNode*i=phead;i!= nullptr;i=i->next)
            cout<<i->data<<' ';
        cout<<endl<<"--- END ---"<<endl;
    }
};

my_queue_1::my_queue_1() {
    phead = ptail = nullptr;
    _size = 0;
}

my_queue_1::my_queue_1(const my_queue_1 &q) {
    this->_size = q._size;
    if(q.ptail == nullptr)
    {
        this->phead = this->ptail = nullptr;
    }
    else {
        this->phead = (QueueNode*) malloc(sizeof(QueueNode));
        this->ptail = phead;
        phead->data = q.phead->data;
        for (QueueNode *i = q.phead->next; i != nullptr; i = i->next) {
            ptail->next =(QueueNode*) malloc(sizeof(QueueNode));
            ptail = ptail->next;
            ptail->data = i->data;
        }
        ptail->next = nullptr;
    }
}

bool my_queue_1::empty() const {
    return _size == 0;
}

int my_queue_1::size() const {
    return _size;
}

QueueDType my_queue_1::front() const {
    return this->phead->data;
}

QueueDType my_queue_1::back() const {
    return this->ptail->data;
}

void my_queue_1::push(QueueDType val) {
    if(phead == nullptr) {
        phead = (QueueNode*) malloc(sizeof(QueueNode));
        ptail = phead;
        ptail->data =val;
        ptail->next = nullptr;
    }
    this->ptail->next = (QueueNode*) malloc(sizeof(QueueNode));
    this->ptail = ptail->next;
    this->_size++;
    ptail->data = val;
    ptail->next = nullptr;

}

void my_queue_1::pop() {
    if(phead== nullptr)
        return;
    this->_size--;
    if(phead==ptail){
        free(phead);
        phead = ptail = nullptr;
    }
    else{
        QueueNode *P = this->phead;
        for (; P->next->next != nullptr; P = P->next);
        free(ptail);
        ptail = P;
        ptail->next = nullptr;
    }
}

void my_queue_1::swap(my_queue_1 &q) {
    int temp = q._size;
    q._size = this->_size;
    this->_size = temp;

    QueueNode*tmp = q.phead;
    q.phead = this->phead;
    this->phead = tmp;

    tmp = q.ptail;
    q.ptail = this->ptail;
    this->ptail = tmp;
}

//int main(){
//    srand(20);
//    my_queue_1 q1;
//    for (int i = 0; i < 10; ++i) {
//        q1.push(rand()%100);
//    }
//    q1.Print();
////    my_queue_1 q2(q1);
////    q2.Print();
//    my_queue_1 q3;
//    for (int i = 0; i < 10; ++i) {
//        q3.push(rand()%100);
//    }
//    q3.Print();
//    q3.swap(q1);
//    q3.Print();
//    q1.Print();
//    return 0;
//}
//2顺序队列

class my_queue_2{
private:
    QueueDType* data;
    int head;
    int tail;
    int capacity;
public:
    my_queue_2();
    my_queue_2(my_queue_2 const&q);
    ~my_queue_2(){free(data);head=tail=capacity=0;}
    bool empty()const;
    int size()const;
    QueueDType front()const;
    QueueDType back()const;
    void push(QueueDType val);
    void pop();
    void swap(my_queue_2&q);

    void Print(){
        cout<<"---Queue---"<<endl;
        for(int i=0;i<tail;i++){
            cout<<data[i]<<' ';
        }
        cout<<endl<<"---END---"<<endl;
    }
};

my_queue_2::my_queue_2() {
    this->capacity = N;
    this->data = (QueueDType*) malloc(sizeof(QueueDType)*N);
    this->head = this->tail = 0;
}

my_queue_2::my_queue_2(const my_queue_2 &q) {
    this->data = (QueueDType*) malloc(sizeof(QueueDType)*q.capacity);
    for (int i = 0; i <= q.tail; ++i) {
        this->data[i] = q.data[i];
    }
    this->tail = q.tail;
    this->head = q.head;
    this->capacity = q.capacity;
}

bool my_queue_2::empty() const {
    return head == tail;
}

int my_queue_2::size() const {
    return tail-head;
}

QueueDType my_queue_2::front() const {
    return data[head];
}

QueueDType my_queue_2::back() const {
    return data[tail-1];
}

void my_queue_2::push(QueueDType val) {
    if(capacity==tail)
        data = (QueueDType*) realloc(data,2*capacity);
    data[tail] = val;
    tail++;
}

void my_queue_2::pop() {
    if(empty())
        return;
    else {
        for(int i = 0;i<tail-1;i++){
            data[i] = data[i+1];
        }
        tail--;
    }
}

void my_queue_2::swap(my_queue_2 &q) {
    QueueDType*temp =  q.data;
    q.data = this->data;
    this->data = temp;

    int tmp = q.head;
    q.head = this->head;
    this->head = q.head;

    tmp = q.tail;
    q.tail = this->tail;
    this->tail = tmp;

    tmp = q.capacity;
    q.capacity = this->capacity;
    this->capacity = tmp;
}

int main(){
    srand(10);
    my_queue_2 q1;
    cout<<q1.empty()<<endl;

    for(int i=0;i<N;i++){
        q1.push(rand()%100);
    }
    q1.Print();
    cout<<q1.size()<<endl;
//    cout<<q1.back()<<endl;
//    cout<<q1.front()<<endl;
    q1.pop();
    q1.Print();
    my_queue_2 q2(q1);
    q2.Print();
    my_queue_2 q3;
    for(int i=0;i<14;i++){
        q3.push(rand()%100);
    }
    q3.Print();
    cout<<q3.size()<<endl;
    q3.swap(q2);
    q2.Print();
    return 0;
}


