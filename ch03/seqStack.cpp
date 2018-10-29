#include<iostream>
#include<ostream>
#include"seqStack.h"
using namespace std;

int main(int argc, char const *argv[])
{
    SeqStack<int> seqs(70);
    seqs.Push(3);
    seqs.Push(4);
    seqs.Push(5);
    seqs.Push(36);
    seqs.Push(7);
    seqs.Push(8);
    seqs.Push(9);
    cout<<seqs<<endl;
    return 0;
}