#include<iostream>
#include"linkedStack.h"
using namespace std;

int main(int argc, char const *argv[])
{
    LinkedStack<int> list;
    list.Push(5);
    list.Push(4);
    list.Push(3);
    list.Push(7);
    list.Push(8);
    list.Push(0);
    int x;
    list.getTop(x);
    cout<<list<<endl;
    cout<<"--------------"<<endl;
    cout<<x<<endl;
    return 0;
}