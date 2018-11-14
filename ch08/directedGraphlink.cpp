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
    // (d,e,31)
    // (c,d,53)
    // (d,e,31)
    DirectedGraphlink<char,int> graph(20);
    graph.insertVertex('a');
    graph.insertVertex('b');
    graph.insertVertex('c');
    graph.insertVertex('d');
    graph.insertVertex('e');
    graph.insertVertex('f');
    graph.insertVertex('g');
    graph.insertEdge(0,1,28);
    graph.insertEdge(0,5,10);
    graph.insertEdge(1,6,14);
    graph.insertEdge(1,2,16);
    graph.insertEdge(2,3,12);
    graph.insertEdge(3,6,18);
    graph.insertEdge(3,4,22);
    graph.insertEdge(4,6,24);
    graph.insertEdge(4,5,25);
    // graph.insertEdge(0,1,24);
    // graph.insertEdge(0,3,46);
    // graph.insertEdge(1,5,55);
    // graph.insertEdge(2,1,15);
    // graph.insertEdge(2,5,15);
    // graph.insertEdge(4,0,15);
    // graph.insertEdge(4,1,15);
    // graph.insertEdge(4,5,15);
    // graph.insertEdge(2,0,55);
    // graph.insertEdge(1,2,15);
    // graph.insertEdge(1,4,67);
    // graph.insertEdge(2,4,37);
    // graph.insertEdge(2,3,53);
    // graph.insertEdge(3,4,31);
    // graph.insertEdge(3,2,65);
    cout<<graph;
    // graph.removeEdge(0,1);
    // cout<<"删除c点";
    // graph.removeVertex(2);
    // cout<<graph;
    // cin>>graph;
    // cout<<graph;
    // graph.removeEdge(0,1);
    // graph.removeVertex(0);
    // cout<<graph;
    cout<<"DFS result is:"<<endl;
    // 从a点开始
    DFS(graph,'a');

    cout << "BFS result is:";
    BFS(graph,'a');
    return 0;
}