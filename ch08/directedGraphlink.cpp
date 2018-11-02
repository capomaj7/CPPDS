#include<iostream>
#include"directedGraphlink.h"
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
    DirectedGraphlink<char,int> graph(20);
    graph.insertVertex('a');
    graph.insertVertex('b');
    graph.insertVertex('c');
    graph.insertVertex('d');
    graph.insertVertex('e');
    graph.insertEdge(0,1,24);
    graph.insertEdge(0,2,46);
    graph.insertEdge(2,0,55);
    graph.insertEdge(1,2,15);
    graph.insertEdge(1,4,67);
    graph.insertEdge(2,4,37);
    graph.insertEdge(2,3,53);
    graph.insertEdge(3,4,31);
    graph.insertEdge(3,2,65);
    cout<<graph;
    // graph.removeEdge(0,1);
    graph.removeVertex(2);
    cout<<graph;
    // cin>>graph;
    // cout<<graph;
    // graph.removeEdge(0,1);
    // graph.removeVertex(0);
    // cout<<graph;
    return 0;
}