#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include<iostream>
#include <stdlib.h>
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

};

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



#endif