#include <iostream>
#include<stdlib.h>
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
using namespace std;
template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *link;
    // 初始化指针
    LinkNode(LinkNode<T> *prt = NULL) { link = prt; };
    // 初始化数据域和指针域
    LinkNode(const T& item, LinkNode<T> *prt = NULL)
    {
        data = item;
        link = prt;
    }
};
template <class T>
class List
{
  protected:
    LinkNode<T> *first;

  public:
    List() { first = new LinkNode<T>; };
    // x下面这个构造函数头节点存储相应的信息
    List(const T &x) { first = new LinkNode<T>(x); };
    // 复制构造函数，即拷贝构造函数，用另一个对象值初始化一个新的构造的对象
    List(List<T> &L);
    // 析构函数最后只剩下头结点
    ~List() { makeEmpty(); };
    void makeEmpty();
    int Length() const;
    LinkNode<T> *getHead() const { return first; };
    LinkNode<T> *Search(T x);
    LinkNode<T> *Locate(int i);
    bool getData(int i, T &x) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x);
    bool Remove(int i, T &x);
    // 带表头结点的是否为空表
    bool IsEmpty() const
    {
        return first->link == NULL ? true : false;
    };
    //这里不设置为慢，所以直接为false
    bool IsFull() const { return false; };
    void Sort();
    void input();
    void inputFront(T endTag);
    void output();
    List<T> &operator=(List<T> &L);
};
// 复制构造函数
template <class T>
List<T>::List(List<T> &L)
{
    T value;
    // 被复制的链表的头结点
    LinkNode<T> *srcptr = L.getHead();
    LinkNode<T> *destptr = first = new LinkNode<T>;
    // 给结点赋值
    while (srcptr->link != NULL)
    {
        value = srcptr->link->data;
        destptr ->link=new LinkNode<T>(value);
        destptr =destptr ->link;
        srcptr =srcptr ->link;
    }
    destptr ->link=NULL;
};
template<class T>
void List<T>::makeEmpty(){
    LinkNode <T>*q;
    while(first ->link!=NULL){
        q=first ->link;
        first ->link=q ->link;
        // 要一个结点一个结点的删除，回收
        delete q;

    }
};
template<class T>
int List<T>::Length()const{
    LinkNode <T> *p=first ->link;
    int count=0;
    while(p!=NULL){
        p=p ->link;
        count++;
    }
    return count;
};

template<class T>
LinkNode <T>* List<T>::Search(T x){
    LinkNode <T> *current =first ->link;
    while(current!=NULL){
        if(current ->data==x)break;
        else
        current=current ->link;
    }
    return current;
};

template<class T>
LinkNode<T>*List<T>::Locate(int i){
    if(i<0)return NULL;
    LinkNode<T> *current=first;
    int k=0;
    while(current!=NULL&&k<i){
        current=current ->link;
        k++;
    }
    return current;
}

template<class T>
bool List<T>::getData(int i,T& x)const{
    if(i<=0)return NULL;
    LinkNode<T> *current =Locate(i);
    if(current==NULL)return false;
    else{
        x=current ->data;
        return true;
    }
};

template<class T>
void List<T>::setData(int i,T& x){
    if(i<=0)return ;
    LinkNode<T> *current=Locate(i);
    if(current==NULL)return;
    else
        current ->data=x;
};

// 将新元素x插入到第i个后面
template<class T>
bool List<T>::Insert(int i,T& x){
    LinkNode<T> *current =Locate(i);
    if(current==NULL)return false;
    LinkNode<T> *newNode= new LinkNode<T>(x);
    if(newNode==NULL){cerr<<"error node"<<endl;exit(1);}
    newNode ->link=current ->link;
    current ->link=newNode;
    return true;
};

template<class T>
bool List<T>::Remove(int i,T& x){
    LinkNode<T>*current =Locate(i-1);
    // current定位是定位在删除元素之前的一个元素
    if(current==NULL||current ->link==NULL)return false;

    LinkNode<T> *del=current ->link;
    x=del ->data;
    current ->link= del ->link;
    delete del;
    return true;
};

// 这里是后插法
template<class T>
void List<T>::input(){
    cout<<"please enter the amount of list"<<endl;
    int num;
    cin>>num;
    LinkNode<T> *p=first;
    for(int i=0;i<num;i++){
        T value;
        cout<<"please enter one T"<<endl;
        cin>>value;
        p->link=new LinkNode<T>(value);
        if(p ->link==NULL){cerr<<"error memery"<<endl;exit(1);}
        p=p ->link;
    }
}

template<class T>
void List<T>::output(){
    LinkNode<T>*current=first ->link;
    while(current!=NULL){
        cout<<current ->data<<endl;
        current=current ->link;
    }
}

template<class U>
List<U>& List<U>::operator =(List<U>&L){
    U value;
    LinkNode<U>*scrptr=L.getHead();
    LinkNode<U>*destptr=first=new LinkNode<U>;
    while(scrptr ->link){
        value=scrptr ->link ->data;
        destptr ->link=new LinkNode<U>(value);
        destptr=destptr ->link;
        scrptr =scrptr ->link;
    }
    destptr ->link=NULL;
    return *this;
}

// endTag是结束标志
template<class T>
void List<T>::inputFront(T endTag){
    LinkNode<T>*newNode;
    T val;
    makeEmpty();
    cin>>val;
    while(val!=endTag){
        newNode=new LinkNode<T>(val);
        if(newNode==NULL){cerr<<"error"<<endl;exit(1);}
        newNode ->link=first ->link;
        first ->link=newNode;
        cin>>val;
    }
}
#endif