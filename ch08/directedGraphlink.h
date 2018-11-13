#ifndef _DirectedGRAPHLINK_H_
#define _DirectedGRAPHLINK_H_
#include <iostream>
#include <stdlib.h>
#include "../ch03/linkedQueue.h"
using namespace std;
const int DefaultVertices = 30;
const int maxWeight = 1024;
template <class T, class E>
//边结点的定义
struct Edge
{
    // 定义下个结点所在的位置
    int dest;
    // 权重
    E cost;
    // 下一条边链指针
    Edge<T, E> *link;
    Edge() {}
    Edge(int num, E weigh) : dest(num), cost(weigh), link(NULL) {}
    bool operator!=(Edge<T, E> &R) const
    {
        return (dest != R.dest) ? true : false;
    }
};

template <class T, class E>
struct Vertex
{
    // 放顶点信息的
    T data;
    // 放指向边结点的
    Edge<T, E> *adj;
};

template<class T,class E>
class DirectedGraphlink{
    template<class M,class N>
    friend istream & operator >>(istream &in,DirectedGraphlink<M,N>&G);
    template<class M,class N>
    friend ostream & operator <<(ostream &out,DirectedGraphlink<M,N>&G);
    private:
    // 最大的顶点数
      int maxVertices;
    //   边的个数
      int numEdges;
    //   顶点的个数
      int numVertices;
    //   顶点表（各边链表的头节点）
      Vertex<T, E> *NodeTable;
    public:
    DirectedGraphlink(int sz =DefaultVertices);
    ~DirectedGraphlink();
    //取位置为i的顶点中的值
    T getValue(int i){return (i>=0&&i<numVertices)?NodeTable[i].data:'0';}
    //返回边v1，v2上的权值
    E getWeight(int v1,int v2);
    //取顶点v的第一个邻接顶点
    int getFirstNeighbor(int v);
    //取v的邻接顶点w的下一邻接顶点
    int getNextNeighor(int v,int w);
    // 插入顶点v
    bool insertVertex(const T &v);
    // 插入边（v1,v2)，权值为cost
    bool insertEdge(int v1,int v2,E cost);
    // 移除点
    bool removeVertex(int x);
    // 移除边
    bool removeEdge(int v1,int v2);
    // 返回顶点数
    int NumberOfVertices(){return numVertices;}
    // 返回边的数量
    int NumberofEdge(){return numEdges;}
    // 返回顶点所在的索引
    int getVertexPos(const T Vertex)
      {
          for (int i = 0; i < numVertices; i++)
          {
              if (NodeTable[i].data == Vertex)
                  return i;
          }
          return -1;
      }

};

template <class T, class E>
DirectedGraphlink<T, E>::DirectedGraphlink(int sz)
{
    maxVertices = sz;
    numVertices = 0;
    numEdges = 0;
    NodeTable = new Vertex<T, E>[maxVertices];
    if (NodeTable == NULL)
    {
        cerr << "error" << endl;
        exit(1);
    }
    for (int i = 0; i < maxVertices; i++)
        NodeTable[i].adj = NULL;
}
template <class T, class E>
DirectedGraphlink<T, E>::~DirectedGraphlink()
{
    for (int i = 0; i < numVertices; i++)
    {
        Edge<T, E> *p = NodeTable[i].adj;
        while (p)
        {
            NodeTable[i].adj = p->link;
            delete p;
            p = NodeTable[i].adj;
        }
    }
    delete[] NodeTable;
}

template <class T, class E>
int DirectedGraphlink<T, E>::getFirstNeighbor(int v)
{
    if (v != -1)
    {
        Edge<T, E> *p = NodeTable[v].adj;
        if (p)
            return p->dest;
    }
    return -1;
}

template <class T, class E>
int DirectedGraphlink<T, E>::getNextNeighor(int v, int w)
{
    if (v != -1)
    {
        Edge<T, E> *p = NodeTable[v].adj;
        while (p && p->dest != w)
            p = p->link;
        // 要考虑到除了w还有w下一个结点
        if (p && p->link)
            return p->link->dest;
    }
    return -1;
}

template <class T, class E>
E DirectedGraphlink<T, E>::getWeight(int v1, int v2)
{
    if (v1 != -1 && v2 != -1)
    {
        Edge<T, E> *p = NodeTable[v1].adj;
        while (p && p->dest != v2)
        {
            p = p->link;
        }
        if (p)
            return p->cost;
    }
    return 0;
}

template <class T, class E>
bool DirectedGraphlink<T, E>::insertVertex(const T &vertex)
{
    if (numVertices == maxVertices)
        return false;
    NodeTable[numVertices].data = vertex;
    numVertices++;
    return true;
}
// 消除行就行了吧，但是为什么要有那么多其他的操作
// 因为除了把点消除了之外还要把和他有关系的边消除了
// c++要严谨缜密
template <class T, class E>
bool DirectedGraphlink<T, E>::removeVertex(int v)
{
    if (numVertices == 1 || v < 0 || v >= numVertices)
        return false;
    // p是指向要删除表上的结点
    Edge<T, E> *p,*s,*q;
    int i, k;
    // 有向图先删除v链上的边，即出度的边
    while (NodeTable[v].adj)
    {
        p = NodeTable[v].adj;
        // 结束了一个结点了，继续下一个结点的循环
        NodeTable[v].adj = p->link;
        delete p;
        numEdges--;
    }
    // 删除入读的边
    for(int i=0;i<numVertices;i++){
        if(i==v)continue;
        // 在每一条脸上寻找v的身影
        p=NodeTable[i].adj,s=p;
        while(p&&p ->dest!=v){
            // 思路是iv
            q=p;
            p =p ->link;
        }
        if(p){
            if(p==s) NodeTable[i].adj=p ->link;
            else
             q ->link=p ->link;
             delete p;
             numEdges--;
        }
    }
    numVertices--;
    // 用最后一个来填补新的一个,注意这里已经在上面做过--自减操作了
    NodeTable[v].data = NodeTable[numVertices].data;
    NodeTable[v].adj = NodeTable[numVertices].adj;
    p = NodeTable[v].adj;
    // 修改和新边关联的结点的信息
    for(int i=0;i<numVertices;i++){
        if(i==v) continue;
        // 在每一条脸上寻找v的身影
        s=NodeTable[i].adj;
        while(s){
            // 当然也可以吧removeEdge中的一些代码拿过来用
            if(s ->dest==numVertices){s ->dest=v;break;}
            else s= s ->link;
        }
    }
    // 感觉要将最后一个给释放了
    // NodeTable[numVertices].adj=NULL;
    // Vertex <T,E> *t=NodeTable[numVertices];
    // delete t; 
    return true;
}

// 这里是向图的插入
template <class T, class E>
bool DirectedGraphlink<T, E>::insertEdge(int v1, int v2, E weight)
{
    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
    {
        Edge<T, E> *q, *p = NodeTable[v1].adj;
        while (p && p->dest != v2)
            p = p->link;
        // 因为要插入，看看是不是已存在这个边，如果存在，就不插入了
        if (p)return false;
        // p不存在的时候创建存储v2结点信息，使用前插法
        p = new Edge<T, E>;
        p->dest = v2;
        p->cost = weight;
        p->link = NodeTable[v1].adj;
        NodeTable[v1].adj = p;
        numEdges++;
        return true;
    }
    return false;
}

// 删除边的思路是类似链表删除结点，这里要用它的前驱
template <class T, class E>
bool DirectedGraphlink<T, E>::removeEdge(int v1, int v2)
{
    if (v1 != -1 && v2 != -1)
    {
        // q是p的前驱
        Edge<T, E> *p = NodeTable[v1].adj, *q = NULL, *s = p;
        while (p && p->dest != v2)
        {
            q = p;
            p = p->link;
        }
        if (p)
        {
            // 如果p就是边链表的首个结点，就直接删除
            if (p == s)
                NodeTable[v1].adj = p->link;
            else
                q->link = p->link;
            delete p;
            numEdges--;
            return true;
        }
        
    }
        //下面一行的含义是如果连接表一开始就是空就没有元素删除
        //还有就是之后遍历一遍链表没找到也是p为空    
        return false;
}

template <class T, class E>
istream &operator>>(istream &in, DirectedGraphlink<T, E> &G)
{
    int i, j, k, n, m;
    // n为顶点数，m为边数
    T e1, e2;
    E weight;
    cout << "please enter numvertex and numedge" << endl;
    in >> n >> m;
    for (i = 0; i < n; i++)
    {
        cout << "please enter " << i + 1 << "vertex" << endl;
        in >> e1;
        G.insertVertex(e1);
    }
    i = 0;
    while (i < m)
    {
        cout << "please enter " << i + 1 << " pair of vertex and it weigh" << endl;
        in >> e1 >> e2 >> weight;
        j = G.getVertexPos(e1);
        k = G.getVertexPos(e2);
        if (j == -1 || k == -1)
        {
            cout << "errer,not exsit vertex that you enter,check it" << endl;
        }
        else
        {
            G.insertEdge(j, k, weight);
            i++;
        }
    }
    cout << "success insert vertices and edges" << endl;
    return in;
}

template <class T, class E>
ostream &operator<<(ostream &out, DirectedGraphlink<T, E> &G)
{
    int i, j, k, n, m;
    // n为顶点数，m为边数
    T e1, e2;
    E weight;
    n = G.NumberOfVertices();
    m = G.NumberofEdge();
    out << "vertices and edges num:";
    out << n << "," << m << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            weight = G.getWeight(i, j);
            if (weight > 0 && weight < maxWeight)
            {
                e1 = G.getValue(i);
                e2 = G.getValue(j);
                out << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
            }
        }
    }
    return out;
}

// DFS的遍历的子过程，这里原因有递归的存在，访问数组不能放在函数里面
template <class T, class E>
void DFSTraverse(DirectedGraphlink<T, E> &G, int v, bool visited[])
{
    // 获取顶点访问，并且标记访问为true
    cout << G.getValue(v) << " ";
    visited[v] = true;
    int w = G.getFirstNeighbor(v);
    while (w != -1)
    {
        if (visited[w] == false)
            DFSTraverse(G, w, visited);
        w = G.getNextNeighor(v, w);
    }
    // 也可以使用for循环
    // for(int w=G.getFirstNeighbor(v);w!=-1;G.getNextNeighor(v,w))
    //     if(!visited[w])DFS(G,w,visited);
}

// 深度优先搜索，有回溯和探查
template <class T, class E>
void DFS(DirectedGraphlink<T, E> &G, const T &v)
{
    int i, loc, n = G.NumberOfVertices();
    bool *visited = new bool[n];
    for (i = 0; i < n; i++)
        visited[i] = false;
    loc = G.getVertexPos(v);
    DFSTraverse(G, loc, visited);
    delete[] visited;
    cout << endl;
}

// 广度搜索，连通图的，类似层遍历
template <class T, class E>
void BFS(DirectedGraphlink<T, E> &G, const T &v)
{
    int i, w, n = G.NumberOfVertices();
    bool *visited = new bool[n];
    for (i = 0; i < n; i++)
        visited[i] = false;
    int loc = G.getVertexPos(v);
    cout << G.getValue(loc) << " ";
    visited[loc] = true;
    LinkedQueue<int> Q;
    Q.EnQueue(loc);
    while (!Q.IsEmpty())
    {
        Q.DeQueue(loc);
        w = G.getFirstNeighbor(loc);
        while (w != -1)
        {
            if (visited[w] == false)
            {
                cout << G.getValue(w) << " ";
                visited[w] = true;
                Q.EnQueue(w);
            }
            // 找关于loc的w的后一个结点
            w = G.getNextNeighor(loc, w);
        }
    }
    delete[] visited;
    cout << endl;
}

// 拓扑排序()
template<class T,class E>
void TopologicalSort(DirectedGraphlink <T,E> &G)
{
    int i,j,w,v;
    int top=-1;
    int n=G.NumberOfVertices();
    int *count=new int[n];
    for(i=0;i<n;i++)count[i]=0;
    cin>>i>>j;
    while(i>-1&&i<n&&j>-1&&j<n){
        G.insertEdge(i,j);
        count[j]++;
        cin>>i>>j;
    }
    for(i=0;i<n;i++)
        if(count[i]==0){count[i]=top;top=i;}
    for(i=0;i<n;i++)
        if(top==-1){
            count<<"no circle"<<endl;
            exit(1);
        }else{
            v=top;
            top=count[top];
            count<<G.getValue(v)<<" "<<endl;
            w=G.getFirstNeighbor(v);
            while(w!=-1){
                if(--count[w]==0)
                {
                    cout[w]=top;
                    top=w;

                }
                w=G.getNextNeighor(v,w);
            }
        }
} 
#endif