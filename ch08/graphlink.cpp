#include <iostream>
#include "graphlink.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Graphlink<char, int> graph(20);
    // cin>>graph;
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
    cout << graph;
    // char v;
    // cout << "please enter one vertex(char type):";
    // cin >> v;
    // graph.removeEdge(0,1);
    // bool rem= graph.removeVertex(0);
    // cout<<graph;
    // cout<<"DFS result is:"<<endl;
    // DFS(graph,v);

    // cout << "BFS result is:";
    return 0;
}