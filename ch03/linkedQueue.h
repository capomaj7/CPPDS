#include<iostream>
#include"../ch02/linkedList.h"
using namespace std;
template<class T>
// 这个链表不是带头结点
class LinkedQueue{
    protected:
    // front是指向第一个结点(不是头节点)，rear指向的是尾结点
    LinkNode<T>*front,*rear;
    public:
    LinkedQueue():front(NULL),rear(NULL){}
    ~LinkedQueue(){makeEmpty();}
    // 进队
    bool EnQueue(const T &x);
    // 出队
    bool DeQueue(T &x);
    bool getFront(T &x)const;
    void makeEmpty();
    bool IsEmpty()const{return (front==NULL)?true:false;}
    int getSize()const;
    template<class U>    
    friend ostream & operator <<(ostream & os,LinkedQueue<U>&Q);
};
template<class T>
void  LinkedQueue<T>::makeEmpty(){
    LinkNode<T>*p;
    while(front){
        p=front;
        front=front ->link;
        delete p;
    }
}

template<class T>
bool LinkedQueue<T>::EnQueue(const T &x){
    if(front==NULL){
        front=rear=new LinkNode<T>(x);
        if(front==NULL)return false;
    }else
    {
        rear ->link =new LinkNode<T>(x);
        if(rear ->link==NULL)return false;
        rear=rear ->link;
    }
    return true;
}

template<class T>
bool LinkedQueue<T>::DeQueue(T &x){
    if(IsEmpty())return false;
    LinkNode<T> *p=front;
    x=p ->data;
    front = front ->link;
    delete p;
    return true;
}

template<class T>
bool LinkedQueue<T>::getFront(T &x)const{
    if(IsEmpty())return false;
    x=front ->data;
    return true;
}

template<class T>
int LinkedQueue<T>::getSize()const{
    int k=0;
    LinkNode<T> *p=front;
    while(p){
        k++;
        p=p ->link;
    }
    return k;
}

template <class T>
ostream &operator<<(ostream &os, LinkedQueue<T> &Q)
{
    // 注意这里是函数，不是属性
    os << "Queue num is :"<< Q.getSize() << endl;
    LinkNode<T> *p = Q.front;
    int i = 0;
    while (p)
    {
        os << ++i << "out:" << p->data << endl;
        p = p->link;
    }
    return os;
}