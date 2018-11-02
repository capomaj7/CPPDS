#include<iostream>
#include <stdlib.h>
using namespace std;
const int DefaultVertices=30;
const int maxWeight=1024;
template<class T,class E>
class DirectedGraphmtx{
    // 重载友元函数
    template<class M,class N>
    friend istream &operator >>(istream &in,DirectedGraphmtx<M,N> &G);
    template<class M,class N>
    friend ostream &operator <<(ostream &out,DirectedGraphmtx<M,N> &G);
    private:
        // 用于存储顶点的一维数组
        T *VerticesList;
        // 邻接矩阵
        E **Edge;
        int maxVertices;
        int numEdges;
        int numVertices;
        // 给出顶点在途中的位置的
        int getVertexPos(T vertex){
            for(int i=0;i<numVertices;i++)
                if(VerticesList[i]==vertex)return i;
            return -1;
        }
    public:
    DirectedGraphmtx(int sz=DefaultVertices);
    ~DirectedGraphmtx(){delete []VerticesList;delete[]Edge;}
    // 去i顶点的值
    T getValue(int i){
        return (i>=0&&i<numVertices)?VerticesList[i]:'0';
    }
    E getWeight(int v1,int v2){
        return (v1!=-1&&v2!=-1)?Edge[v1][v2]:0;
    }
    int getFirstNeighbor(int v);
    int getNextNeighor(int v,int w);
    bool insertVertex(const T &v);
    bool insertEdge(int v1,int v2,E cost);
    bool removeVertex(int x);
    bool removeEdge(int v1,int v2);
    int NumberOfVertices(){return numVertices;}
    int NumberofEdge(){return numEdges;}
    void printGraphmtx();
};

template<class T,class E>
DirectedGraphmtx<T,E>::DirectedGraphmtx(int sz){
    maxVertices=sz;numEdges=0;numVertices=0;
    int i,j;
    VerticesList=new T[maxVertices];
    Edge =(E **)new E *[maxVertices];
    for(i=0;i<maxVertices;i++)
        Edge[i]=new E[maxVertices];
    // 对角线设置为0，其他的部分设置成最大
    for(i=0;i<maxVertices;i++)
        for(j=0;j<maxVertices;j++)
            Edge[i][j]=(i==j)?0:maxWeight;
}

// 输入时要找的结点的索引，输出的是用矩阵存储的第一个连接顶点的索引
template<class T,class E>
int DirectedGraphmtx<T,E>::getFirstNeighbor(int v){
    if(v!=-1){
        for(int col=0;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)return col;
    }
    return -1;
}

// v是点，w是v相连接的点，函数要找的是w之后的v的连接点
template<class T,class E>
int DirectedGraphmtx<T,E>::getNextNeighor(int v,int w)
{
    if(v!=-1&&w!=-1){
        for(int col=w+1;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)return col;
    }
    return -1;
}

template<class T,class E>
bool DirectedGraphmtx<T,E>::insertVertex(const T &vertex){
    if(numVertices==maxVertices)return false;
    VerticesList[numVertices++]=vertex;
    return true;
    
}

// 解释参见353
template<class T,class E>
bool DirectedGraphmtx<T,E>::removeVertex(int v){
    if(v<0||v>=numVertices)return false;
    // 图的结构可以没有边，但是要有点
    if(numVertices==1)return false;
    int i,j;
    // 将最后的一个结点转移到要删除的结点上
    VerticesList[v]=VerticesList[numVertices-1];
    // 
    for(i=0;i<numVertices;i++)
        // 第一个是v点的度，第二个是v点的出度
        if((Edge[i][v]>0&&Edge[i][v]<maxWeight)||(Edge[v][i]>0&&Edge[v][i]<maxWeight))numEdges--;
    // 用最后一列填补第v列
    for(i=0;i<numVertices;i++)
        Edge[i][v]=Edge[i][numVertices-1];
    numVertices--;
    // 用最后一行填补第v行
    for(j=0;j<numVertices;j++)
    Edge[v][j]=Edge[numVertices][j];
    return true;
}

// 有向图的插入.插入v1到v2
template<class T,class E>
bool DirectedGraphmtx<T,E>::insertEdge(int v1,int v2,E cost){
    // 这里的if的最后的条件让无向图出现重复后权重还是原来的
    if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]==maxWeight){
        // 需要更加细致，别吧=弄成==
        Edge[v1][v2]=cost;
        // cout<<Edge[v1][v2]<<endl;
        numEdges++;
        return true;
    }
    else return false;
}

// 有向图的删除，从v1到v2
template<class T,class E>
bool DirectedGraphmtx<T,E>::removeEdge(int v1,int v2)
{
    if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]>0
    &&Edge[v1][v2]<maxWeight){
        Edge[v1][v2]=maxWeight;
        numEdges--;
        return true;
    }
    else return false;
    
}

template<class T,class E>
istream & operator >>(istream &in,DirectedGraphmtx<T,E>&G){
    int i,j,k,n,m;
    // n为顶点数，m为边数
    T e1,e2; E weight;
    cout<<"please enter numvertex and numedge"<<endl;
    in>>n>>m;
    for(i=0;i<n;i++){
        cout<<"please enter "<<i+1<<"vertex"<<endl;
        in>>e1;
        G.insertVertex(e1);
    }
    i=0;
    while(i<m)
    {
        cout<<"please enter "<<i+1<<" pair of vertex and it weigh"<<endl;
        in>>e1>>e2>>weight;
        j=G.getVertexPos(e1);
        k=G.getVertexPos(e2);
        if(j==-1||k==-1){
            cout<<"errer"<<endl;    
        }else{
            G.insertEdge(j,k,weight);
            i++;
        }
    }
    cout<<"success insert vertices and edges"<<endl;
    return in;
}

template<class T,class E>
ostream &operator <<(ostream &out,DirectedGraphmtx<T,E>&G){
    int i,j,k,n,m;
    // n为顶点数，m为边数
    T e1,e2; E weight;
    n=G.NumberOfVertices();
    m=G.NumberofEdge();
    out<<"vertices and edges num:";
    out<<n<<","<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            weight=G.getWeight(i,j);
            if(weight>0&&weight<maxWeight){
                e1=G.getValue(i);
                e2=G.getValue(j);
                out<<"("<<e1<<","<<e2<<","<<weight<<")"<<endl;
            }
        }
    }
    return out;
}

template<class T,class E>
void DirectedGraphmtx<T,E>::printGraphmtx(){
    if(numEdges==0) {cerr<<"error"<<endl;exit(1);}
    for(int i=0;i<numVertices;i++)
        cout<<VerticesList[i]<<"\t";
    cout<<endl;
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++)
            cout<<Edge[i][j]<<"\t";
        cout<<endl;
    }
        
}