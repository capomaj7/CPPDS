#include<assert.h>
#include<ostream>
#include<iostream>
using namespace std;
template<class T>
// 这里定义的是循环队列，普通的队列有问题，但是循环队列要牺牲一个空间，这样可以判断是否空和满
class SeqQueue{
    protected:
    int rear,front;
    T *elements;
    int maxSize;
    public:
    SeqQueue(int sz=10);
    ~SeqQueue(){delete []elements;}
    bool EnQueue(const T &x);
    bool DeQueue(T &x);
    bool getFront(T &x)const;
    void makeEmpty(){front=rear=0;}
    bool IsEmpty()const{return (front==rear)?true:false;}
    bool IsFull()const{return ((rear+1)%maxSize==rear)?true:false;}
    int getSize()const{return (rear-front+maxSize)%maxSize;}
    template<class U>
    friend ostream &operator<<(ostream&os ,SeqQueue <U>&Q);
};
template<class T>
SeqQueue<T>::SeqQueue(int sz):front(0),rear(0),maxSize(sz)
{
    elements=new T[maxSize];
    assert(elements!=NULL);
}
template<class T>
bool SeqQueue<T>::EnQueue(const T &x){
    if(IsFull())return false;
    elements[rear]=x;
    rear=(rear+1)%maxSize;
    return true;
}
template<class T>
bool SeqQueue<T>::DeQueue(T &x){
    if(IsEmpty())return false;
    x=elements[front];
    front=(front+1)%maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::getFront(T &x)const{
    if(IsEmpty())return false;
    x=elements[front];
    return true;
}

template<class U>
ostream &operator<<(ostream&os ,SeqQueue <U>&Q){
    os<<"front="<<Q.front<<"\trear="<<Q.rear<<endl;
    for(int i=Q.front;i!=Q.rear;i=(i+1)%Q.maxSize)
    {
        os<<i<<":"<<Q.elements[i]<<endl;
    }
    return os;
}

