#include<iostream>
#include "seqList.h"
using namespace std;
int main(int argc, char const *argv[])
{
    SeqList<int> list(10);
    list.input();
    list.output();
    bool judge=list.IsEmpty();
    bool judge2=list.IsFull();
    int removevalue;
    list.Remove(2,removevalue);
    list.output();
    cout<<"---------------"<<endl;
    cout<<judge<<endl;
    cout<<judge2<<endl;
    cout<<removevalue<<endl;
    return 0;
}