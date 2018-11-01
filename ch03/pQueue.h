#include<assert.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
// 优先级队列数组的默认长度
/* 这里创建的是最小优先级队列，即先搜索最小的元素，删除操作也是最小的元素先删除 */
const int DefaultPQSize=50;
template<class T>
class PQueue{
    protected:
        T *pqelements;
        int count;
        int maxSize;
        // 队列调整
        void adjust();
    public:
    PQueue(int sz=DefaultPQSize);
    ~PQueue(){delete pqelements;}
    bool Insert(const T &x);
    // 将队头元素删去
    bool RemoveMin(T &x);
    bool getFront(T &x)const;
    void makeEmpty(){count=0;}
    bool IsEmpty()const{return (count==0)?true:false;}
    bool IsFull()const{return (count==maxSize)?true:false;}
    int getSize()const{return count;}
};
template<class T>
PQueue<T>::PQueue(int sz):maxSize(sz),count(0){
    pqelements=new T[maxSize];
    assert(pqelements!=NULL);
}

template<class T>
bool PQueue<T>::Insert(const T &x){
    if(count==maxSize)return false;
    pqelements[count++]=x;
    adjust();
}

// 这里相当于插入排序,将元素的最后一个元素调整到前面排序好的元素中，类似插入排序
template<class T>
void PQueue<T>::adjust(){
    T temp=pqelements[count-1];
    int j;
    for(j=count-2;j>=0;j--)
        if(pqelements[j]<temp)break;
        else
            pqelements[j+1]=pqelements[j];
    pqelements[j+1]=temp;
}


template<class T>
bool PQueue<T>::RemoveMin(T &x){
    if(count==0)return false;
    x=pqelements[0];
    // 将数组向前移动
    for(int i=1;i<count;i++)pqelements[i-1]=pqelements[i];
    count--;
    return true;
}

template<class T>
bool PQueue<T>::getFront(T &x)const{
    if(cout==0)return false;
    x=pqelements[0];
    return true;
}