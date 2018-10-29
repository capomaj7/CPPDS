#include<iostream>
#include"pQueue.h"
using namespace std;

// 测试最小优先级队列
int main(int argc, char const *argv[])
{
    PQueue <int> queue;
    queue.Insert(4);
    queue.Insert(2);
    queue.Insert(7);
    queue.Insert(1);
    queue.Insert(9);
    queue.Insert(65);
    queue.Insert(9);
    queue.Insert(4);
    int size =queue.getSize();
    for(int i=0;i<size;i++){
        int x;
        queue.RemoveMin(x);
        cout<<x<<endl;
    }
    return 0;
}