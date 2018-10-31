#include<iostream>
#include "graphlink.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Graphlink<char,int >graph(20);
    cin>>graph;
    cout<<graph;
    // graph.removeEdge(0,1);
   bool rem= graph.removeVertex(0);
    cout<<rem;
    return 0;
}