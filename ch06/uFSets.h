#include<iostream>
using namespace std;
const int DefaultSize=10;
class UFSets{
    private:
    int *parent;
    int size;
    public:
    UFSets(int sz=DefaultSize);
    ~UFSets(){delete []parent;}
    UFSets &operator =(UFSets &R);
    void Union(int Root1,int Root2);
    int Find(int x);
    void WeightedUnion(int Root1,int Root2);
};

UFSets::UFSets(int sz){
    size=sz;
    parent=new int[size];
    for(int i=0;i<size;i++)
    parent[i]=-1;
}

UFSets::Find(int x){
    while(parent[x]>=0)x=parent[x];
    return x;
}

void UFSets::Union(int Root1,int Root2){
    parent[Root1]+=parent[Root2];
    parent[Root2]=Root1;
}

void UFSets::WeightedUnion(int Root1,int Root2){
    int r1=Find(Root1);
    int r2=Find(Root2);
    int temp;
    if(r1!=r2){
        temp=parent[r1]+parent[r2];

    }
    if(parent[r2]<parent[r1])
    {
        parent[r1]=r2;
        parent[r2]=temp;


    }
    else{
        parent[r2]=r1;
        parent[r1]=temp;
    }
}