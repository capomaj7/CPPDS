#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include<iostream>
#include<stdlib.h>
using namespace std;
const int  DefaultSize=10;
// 这里用的是一维数组（按照完全二叉树来存储最小堆
template<class T>
class MinHeap{
    private:
    T *heap;
    // 元素的个数，即结点的个数
    int  currentSize;
    // 最多允许的元素个数
    int maxHeapSize;
    // 从start下滑到m
    void siftDown(int start,int m);
    // 从start上滑到0
    void siftUp(int start);
    public:
    MinHeap(int sz=DefaultSize);
    MinHeap(T arr[],int n); // n是size
    ~MinHeap(){delete []heap;};
    bool Insert(const T &x);
    // 删除顶上最小的元素
    bool RemoveMin(T &x);
    bool IsEmpty()const{return (currentSize==0)?true:false;}
    bool IsFull()const{return (currentSize==maxHeapSize)?true:false;}
    void MakeEmpty(){currentSize=0;}
    int getCurrent(){return currentSize;}
    T * getHeap(){return heap;}
};
template<class T>
void swapValue(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<class T>
MinHeap<T>::MinHeap(int sz){
    maxHeapSize=(DefaultSize<sz)?sz:DefaultSize;
    heap=new T[maxHeapSize];
    if(heap==NULL){cerr<<"error"<<endl;exit(1);}
    currentSize=0;
}

// n是size
template<class T>
MinHeap<T>::MinHeap(T arr[],int n){
    maxHeapSize=(DefaultSize<n)?n:DefaultSize;
    heap=new T[maxHeapSize];
    if(heap==NULL){cerr<<"error"<<endl;exit(1);}
    // 赋值
    for(int i=0;i<n;i++) heap[i]=arr[i];
    currentSize=n;
    // 找出父结点的索引，这里是currentsize所以-2,否则应该是parent=(base-1)/2,当然这里都是索引
    int currentPos=(currentSize-2)/2;
    while(currentPos>=0)
    {
        siftDown(currentPos,currentSize-1);
        currentPos--;
    }

}

template<class T>
void MinHeap<T>::siftDown(int start,int m){
    // i为父，j为左孩子
    int i=start,j=2*i+1;
    T temp=heap[i];
    while(j<=m)
    {
        // 让j指向最小的数，注意这里只是孩子小于父结点，不是让孩子也有关系的
         // 如果j=m，这里的j+1就溢出了
        if(j<m&&heap[j]>heap[j+1])j++;
       
        // if(j<m&&heap[j]>heap[j+1])swapValue(heap[j],heap[j+1]); //naive
        if(temp<=heap[j])break;
        // 让小的上移动，同时更新父节点和子节点
        else{heap[i]=heap[j];i=j;
        // 这里j=2*i+1也行，即更新参数
        j=2*j+1;
        }
        heap[i]=temp;
    }
}

template<class T>
void MinHeap<T>::siftUp(int start)
{
    int j=start,i=(j-1)/2;
    T temp=heap[j];
    while(j>0)
    {
        if(heap[i]<=temp)break;
        else{heap[j]=heap[i];j=i;i=(i-1)/2;}
    }
    heap[j]=temp;
}

template<class T>
bool MinHeap<T>::Insert(const T &x){
    if(currentSize==maxHeapSize)return false;
    heap[currentSize]=x;
    siftUp(currentSize);
    currentSize++;
    return true;
}

// 移除顶上最小的元素
template<class T>
bool MinHeap<T>::RemoveMin(T &x){
    if(currentSize==0)return false;
    x=heap[0];
    heap[0]=heap[currentSize-1];
    // siftup(currentSize-2);
    currentSize--;
    siftDown(0,currentSize-1);
    return true;
}

template<class T>
void printHeap(MinHeap<T> &G)
{
    if(!G.getCurrent())
    cout<<"error"<<endl;
    else{
        T *p=G.getHeap();
        for(int i=0;i<G.getCurrent();i++)
            cout<<p[i]<<" ";
    }
}


#endif