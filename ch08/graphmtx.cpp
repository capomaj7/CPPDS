#include<iostream>
#include"graphmtx.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // 输入详见354
    // 5,6
    // (a,b,24)
    // (a,c,46)
    // (b,c,15)
    // (b,e,67)
    // (c,d,53)
    // (d,e,31)
    Graphmtx<char,int> graph(20);
    cin>>graph;
    cout<<graph;
    // graph.removeEdge(0,1);
    graph.removeVertex(0);
    cout<<graph;
    return 0;
}