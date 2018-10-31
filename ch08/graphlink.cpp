#include<iostream>
#include "graphlink.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Graphlink<char,int >graph(20);
    cin>>graph;
    cout<<graph;
    char v;
    cout<<"please enter one vertex(char type):";
    cin>>v;
    // graph.removeEdge(0,1);
    // bool rem= graph.removeVertex(0);
    // cout<<graph;
    // cout<<"DFS result is:"<<endl;
    // DFS(graph,v);
    
    cout<<"BFS result is:";
    BFS(graph,v);
    return 0;
}