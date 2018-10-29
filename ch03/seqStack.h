#include<assert.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
const int stackIncreament=20;
template<class T>
class SeqStack{
    private:
    T *elements;
    int top;
    int maxSize;
    void overflowProcess();
    public:
    SeqStack(int sz=50);
    ~SeqStack(){delete elements;}
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x);
    bool IsEmpty()const{return (top==-1)?true:false;};
    bool IsFull()const{return (top==maxSize-1)?true:false;};
    int getSize()const{return top+1;};
    void MakeEmpty(){top=-1;};
    // 输出占中元素的重载操作,需要用另一个模板，参考
    // https://blog.csdn.net/a19990412/article/details/78214186?locationNum=7&fps=1
    template<class U>
    friend std::ostream &operator<<(std::ostream &os, SeqStack<U>& s);
};
// 构造函数的单引号是给相应的成员变量赋值
template<class T>
SeqStack<T>::SeqStack(int sz):top(-1),maxSize(sz){
    elements=new T[maxSize];
    // 使用c++断言机制，满足条件继续执行，不符合条件终止程序
    assert(elements!=NULL);
}

// 扩充栈的存储空间
template<class T>
void SeqStack<T>::overflowProcess(){
    T * newArray=new T[maxSize+stackIncreament];
    if(newArray!=NULL){cerr<<"error menery"<<endl;exit(1);}
    for(int i=0;i<=top;i++)newArray[i]=elements[i];
    maxSize+=stackIncreament;
    delete []elements;
    elements=newArray;
}

template<class T>
void SeqStack<T>::Push(const T &x){
    if(IsFull())overflowProcess();
    // 这里是从0开始计数的，原先top=-1,即先+1在进栈
    elements[++top]=x;
}

template<class T>
bool SeqStack<T>::Pop(T &x){
    if(IsEmpty())return false;
    x=elements[top--];
    return true;
}

template<class T>
bool SeqStack<T>::getTop(T &x){
    if(IsEmpty())return false;
    x=elements[top];
    return true;
}

template<class U>
ostream & operator <<(std::ostream &os ,SeqStack<U> &s){
    os<<"top ="<<s.top<<endl;
    for(int i=0;i<=s.top;i++){
        os<<i<<":"<<s.elements[i]<<endl;
    }
    return os;
}

