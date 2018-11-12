/* 思路是，第一次遍历确定入度为0的点的索引数，记录放在数组中，然后循环删除该顶点门，记录count（这里的count相当于学期），然后递归循环 */
// 下面的算法的缺点是改变了原来图的结构
#include <iostream>
#include "directedGraphlink.h"
using namespace std;
int main(int argc, char const *argv[])
{
    //建立有向图，这里12个顶点，用a到i来表示
    DirectedGraphlink<char, int> graph(12);
    graph.insertVertex('a');
    graph.insertVertex('b');
    graph.insertVertex('c');
    graph.insertVertex('d');
    graph.insertVertex('e');
    graph.insertVertex('f');
    graph.insertVertex('g');
    graph.insertVertex('h');
    graph.insertVertex('i');
    graph.insertVertex('j');
    graph.insertVertex('k');
    graph.insertVertex('l');
    // 构建相应的边，因为拓扑排序不需要权重，所以默认这里的权重是0
    graph.insertEdge(0, 1, 1);
    graph.insertEdge(0, 2, 1);
    graph.insertEdge(0, 3, 1);
    graph.insertEdge(0, 11,1);
    graph.insertEdge(1, 2, 1);
    graph.insertEdge(2, 4, 1);
    graph.insertEdge(2, 6, 1);
    graph.insertEdge(2, 7, 1);
    graph.insertEdge(3, 4, 1);
    graph.insertEdge(4, 6, 1);
    graph.insertEdge(5, 7, 1);
    graph.insertEdge(8, 11,1);
    graph.insertEdge(8, 9, 1);
    graph.insertEdge(9, 11,1);
    graph.insertEdge(10, 5,1);
    graph.insertEdge(8, 10,1);
    // 定义记录索引的
    // 注意图的概念必须要顶点至少有一个，可以没有边
    /* while (graph.NumberOfVertices() > 1)
    {
        int indexarr[12], count = 0;
        //标志，为1为找到了，0为没找到
        int flag = 0;
        for (int i = 0; i < graph.NumberOfVertices(); i++)
        {
            int j;
            for (j = 0; j < graph.NumberOfVertices(); j++)
            {
                // 如果
                int firstNodeIndex = graph.getFirstNeighbor(i);
                if (!firstNodeIndex)
                    continue;
                while (firstNodeIndex)
                {
                    int nextNodeIndex = graph.getNextNeighor(i, firstNodeIndex);
                    if (nextNodeIndex == i)
                    {
                        flag = 1;
                        break;
                    }
                }
                // 索引中找到了调出内层循环
                if (flag == 1)
                    break;
            }
            // 如果循环发现遍历的所以都找不到目标是自己，即入度为0
            if (j >= graph.NumberOfVertices())
            {
                indexarr[count++] = i;
            }
        }
        //开始移除点
        if(count>0){
            int m;
            for(m=0;m<count;m++){
                cout<<graph.getValue(m);
                graph.removeVertex(indexarr[m]);
            }
            cout<<"|";
        }
    } */
    // cout<<graph.getValue(0)<<endl;
    cout<<graph<<endl;
    return 0;
}