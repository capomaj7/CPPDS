#include<iostream>
#include"seqQueue.h"
using namespace std;

int main(int argc, char const *argv[])
{
    SeqQueue <char> queue(8);
    queue.EnQueue('a');
    queue.EnQueue('b');
    queue.EnQueue('c');
    queue.EnQueue('d');
    queue.EnQueue('e');
    queue.EnQueue('f');
    cout<<queue<<endl;
    return 0;
}