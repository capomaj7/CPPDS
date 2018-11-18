#include<iostream>
#include<vector>
#include"directedGraphmtx.h"
using namespace std;
// 这里用的模型是376页的例子
template<class T,class E>
void testDijkstra(DirectedGraphmtx <T,E> &graph,int v,E dist[],int path[]){
    // 376页的例子
    graph.insertVertex('a');
    graph.insertVertex('b');
    graph.insertVertex('c');
    graph.insertVertex('d');
    graph.insertVertex('e');
    graph.insertEdge(0,1,10);
    graph.insertEdge(1,2,50);
    graph.insertEdge(0,3,30);
    graph.insertEdge(0,4,100);
    graph.insertEdge(2,4,10);
    graph.insertEdge(3,2,20);
    graph.insertEdge(3,4,60);
    ShortestPathDijkstra(graph,0,dist,path);
    printShortestPathDijkstra(graph,0,dist,path);
}

/* 书上382的图作为例子,这里不想纠结函数对问题 */
template<class T,class E>
void testFloyd(DirectedGraphmtx <T,E>&graph,E a[4][4],int path[4][4]){
    graph.insertVertex('0');
    graph.insertVertex('1');
    graph.insertVertex('2');
    graph.insertVertex('3');
    graph.insertEdge(0,1,1);
    graph.insertEdge(0,3,4);
    graph.insertEdge(1,2,9);
    graph.insertEdge(1,3,2);
    graph.insertEdge(2,3,8);
    graph.insertEdge(2,0,3);
    graph.insertEdge(3,2,6);
    graph.insertEdge(2,1,5);
    Floyd(graph,a,path);
}
template<class T,class E>
void testFloyd2(DirectedGraphmtx <T,E>&graph,E a[4][4],int path[4][4]){
    graph.insertVertex('0');
    graph.insertVertex('1');
    graph.insertVertex('2');
    graph.insertVertex('3');
    graph.insertEdge(0,1,5);
    graph.insertEdge(0,3,7);
    graph.insertEdge(1,2,4);
    graph.insertEdge(1,3,2);
    graph.insertEdge(2,3,2);
    graph.insertEdge(2,0,3);
    graph.insertEdge(3,2,1);
    graph.insertEdge(2,1,3);
    Floyd(graph,a,path);
}
int main(int argc, char const *argv[])
{
    DirectedGraphmtx<char,int> graph(20);
    /* 测试迪杰斯特拉 */
    // int dist[5];
    // int path[5];
    // testDijkstra(graph,0,dist,path);
    /* 测试弗洛伊德，原始的因为不好处理函数的二维的问题统一用a[4][4]限定维度了 */
    int a[4][4];
    int path[4][4];
    testFloyd2(graph,a,path);
    // graph.insertVertex('a');
    // graph.insertVertex('b');
    // graph.insertVertex('c');
    // graph.insertVertex('d');
    // graph.insertVertex('e');
    // graph.insertEdge(0,1,10);
    // graph.insertEdge(1,2,50);
    // graph.insertEdge(0,3,30);
    // graph.insertEdge(0,4,100);
    // graph.insertEdge(2,4,10);
    // graph.insertEdge(3,2,20);
    // graph.insertEdge(3,4,60);
    // cout<<graph<<endl;
    return 0;
}