#include <iostream>
#include<stdlib.h>
using namespace std;
const int defaultSize = 100;
template <class T>
class SeqList
{
  protected:
    T *data;
    int maxSize;
    // last为最后一个元素的索引
    int last;
    void reSize(int newSize);
  public:
    SeqList(int sz);
    SeqList(SeqList<T> &L);
    ~SeqList(){delete[] data;};
    int Size() const {return maxSize;};
    int Length() const {return last + 1;};
    int Search(T &x) const;
    int Locate(int i) const;
    //这里的i不是索引，而是第几个
    bool getData(int i, T &x) const
    {
        if (i > 0 && i <= last + 1)
        {
            x = data[i - 1];
            return true;
        }
        return false;
    };
    void setData(int i, T &x)
    {
        if (i > 0 && i <= last + 1)
            data[i - 1] = x ;
    };
    bool Insert(int i,T &x);
    bool Remove(int i,T &x);
    bool IsEmpty(){return (last==-1)?true:false;};
    bool IsFull(){return (last==maxSize-1)?true:false;};
    void input();
    void output();
    SeqList<T>operator =(SeqList<T>&L);
};
template<class T>
//构造函数
SeqList<T>::SeqList(int sz){
    if(sz>0){
        maxSize=sz;
        last=-1;
        data=new T[maxSize];
        if(data==NULL){
            cerr<<"not enough mer"<<endl;
            exit(1);
        }
    }
};
// 构造函数
template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    maxSize = L.Size();
    last = L.Length() - 1;
    T value;
    data = new T[maxSize];
    if (data == NULL)
    {
        cerr << "error" << endl;
        exit(1);
    }
    for (int i = 1; i <= last + 1; i++)
    {
        L.getData(i, value);
        data[i - 1] = value;
    }
};
// 重新分配空间
template <class T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize < 0)
    {
        cerr << "error2" << endl;
        return;
    }
    if (newSize != maxSize)
    {
        T *newarray = new T[newSize];
        if (newarray == NULL)
        {
            cerr << "error3" << endl;
            exit(1);
        }
        int n = last + 1;
        // 原数组的首地址
        T *srcptr = data;
        // 目的数组的首地址
        T *desptr = newarray;
        // 将原数组的元素赋值给目标数组中去
        while (n--)
            *desptr++ = *srcptr++;
        delete[] data;
        data = newarray;
        maxSize = newSize;
    }
};
// 根据值来找相应的第几个元素
template<class T>
int SeqList<T>::Search(T &x)const{
    for(int i=0;i<=last;i++){
        if(data[i]==x){
            return i+1;
        }
        return 0;
    }
};

// 定位函数，序号是从第一个开始的
template<class T>
int SeqList<T>::Locate(int i)const{
    return (i>=1&&i<=last+1)?i:0;
};

template<class T>
bool SeqList<T>::Insert(int i,T &x){
    // 表满了不能插入了
    if(last==maxSize-1)return false;
    if(i<0||i>last+1)return false;
    // 从后向前移动
    for(int j=last;j>=i;j--)
        data[j+1]=data[j];
    // 这个时候j+1就是i，又可以避免j的域的问题
    data[i]=x;
    last++;
    return true;
    
};

template<class T>
bool SeqList<T>::Remove(int i,T &x){
    // 表是空的话不能插入
    if(last==-1)return false;
    if(i<1||i>last+1)return false;
    // 这个时候x用于返回被删除的元素
    x=data[i-1];
    for(int j=i-1;j<=last;j++)
        data[j]=data[j+1];
    last--;
    return true;
};

template<class T>
void SeqList<T>::input(){
    cout<<"输入表中的最后一个元素的索引："<<endl;
    while(1){
        cin>>last;
        if(last<=maxSize-1)break;
        cout<<"num is error"<<endl;
    }
    for(int i=0;i<=last;i++){
        cin>>data[i];
        cout<<"输入的第"<<(i+1)<<"个"<<endl;
    }
};

template<class T>
void SeqList<T>::output(){
    cout<<"元素最后的索引是"<<last<<endl;
    for(int i=0;i<=last;i++){
        cout<<data[i]<<endl;
    }
};

template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L){
    delete []data;
    maxSize=L.Size();
    last=L.Length()-1;
    T value;
    data =new T[maxSize];
    if(data==NULL){
        cerr<<"error"<<endl;
        exit(1);
    }
    for(int i=1;i<=last+1;i++){
        L.getData(i,value);
        data[i-1]=value;
    }
    return *this;
};