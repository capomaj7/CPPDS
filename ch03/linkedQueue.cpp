#include<iostream>
#include"linkedQueue.h"
using namespace std;

int main(int argc, char const *argv[])
{
    LinkedQueue<int> queue;
    queue.EnQueue(3);
    queue.EnQueue(4);
    queue.EnQueue(5);
    queue.EnQueue(6);
    queue.EnQueue(7);
    queue.EnQueue(8);
    queue.EnQueue(39);
    queue.EnQueue(0);
    queue.EnQueue(5);
    cout<<queue<<endl;
    return 0;
}