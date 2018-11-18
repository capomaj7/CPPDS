#include<iostream>
#include"minHeap.h"
using namespace std;
int main(int argc, char const *argv[])
{
    int a[7]={2,0,1,-4,7,-1,4};
    MinHeap<int> heap(a,7);
    heap.Insert(-5);
    printHeap(heap);
    cout<<endl;
    // int a=3,b=4;
    // swapValue(a,b);
    // cout<<a<<""<<b<<endl;
    int x;
    heap.RemoveMin(x);
    cout<<x<<endl;
    printHeap(heap);
    cout<<endl;
    return 0;
}