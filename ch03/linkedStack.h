#include<iostream>
#include"../ch02/linkedList.h"
using namespace std;
template<class T>
class LinkedStack{
    private:
    LinkNode<T>*top;
    public:
    LinkedStack():top(NULL){};
    ~LinkedStack(){makeEmpty();}
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x)const;
    bool IsEmpty()const{return (top==NULL)?true:false;}
    int getSize()const;
    void makeEmpty();
    template<class U>
    friend ostream &operator <<(ostream & os,LinkedStack<U>&s);
};

template<class T>
void LinkedStack<T>::makeEmpty(){
    LinkNode<T>*p;
    while(top){
        p=top;
        top=top ->link;
        delete p;
    }
}

template<class T> 
void LinkedStack<T>::Push(const T&x){
    // 这里经过2个操作，第一个是创建结点，数据域为x，指针域指向的是top所指向的结点，
    // 第二个查找就是修改top指针，改成指向的是进结点，用的前插法链表
    top=new LinkNode<T>(x,top);
}

// 删除栈顶元素，并将栈顶元素用x作为输出
// 需要指针后移和删除该结点
template<class T>
bool LinkedStack<T>::Pop(T &x){
    if(IsEmpty())return false;
    LinkNode<T> *p=top;
    top=top ->link;
    x=p ->data;
    delete p;
    return true;
}

template<class T>
bool LinkedStack<T>::getTop(T &x)const{
    if(IsEmpty())return false;
    x=top ->data;
    return true;

}

template<class T>
int LinkedStack<T>::getSize()const{
    LinkNode<T>*p=top;
    int k=0;
    while(p){p=p ->link;k++;}
    return k++;
}

template<class T>
ostream &operator <<(ostream &os, LinkedStack<T>&s){
    os<<"stack size is:"<<s.getSize()<<endl;
    LinkNode<T>*p=s.top;
    int i=0;
    while(p)
    {
        os<<++i<<"out:"<<p ->data<<endl;
        p=p ->link;
    }
    return os;
}

// 如果同时使用n个栈,类似与邻接链表
// LinkNode<T> *s=new LinkNode<T>[n]