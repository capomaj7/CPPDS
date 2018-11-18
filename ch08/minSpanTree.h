#include<iostream>
using namespace std;
const float maxValue=1024.00;
template<class T,class E>
struct MSTEdgeNode{
    int tail,head;
    E key; 
    MSTEdgeNode():tail(-1),head(-1),key(0){}
    bool operator <=(MSTEdgeNode <T,E>&R){return key<=R.key;}
    bool operator >(MSTEdgeNode <T,E>&R){return key>R.key;}
};

template<class T,class E>
class MinSpanTree{
    protected:
    MSTEdgeNode<T,E> *edgevalue;
    int maxSize,currentsize;
    public:
    MinSpanTree(int sz=maxValue-1):maxSize(sz):currentsize(0)
    {
        edgevalue=new MSTEdgeNode<T,E>[sz];
    }
};
