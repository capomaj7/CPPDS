#include<iostream>
using namespace std;
const int DefaultVertices=30;
const int maxWeight=1024;
template<class T,class E>
class Graphmtx{
    // 重载友元函数
    template<class M,class N>
    friend istream &operator >>(istream &in,Graphmtx<M,N> &G);
    template<class M,class N>
    friend ostream &operator <<(ostream &out,Graphmtx<M,N> &G);
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
    Graphmtx(int sz=DefaultVertices);
    ~Graphmtx(){delete []VerticesList;delete[]Edge;}
    // 去i顶点的值
    T getValue(int i){
        return (i>=0&&i<numVertices)?VerticesList[i]:'e';
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
};

template<class T,class E>
Graphmtx<T,E>::Graphmtx(int sz){
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
int Graphmtx<T,E>::getFirstNeighbor(int v){
    if(v!=-1){
        for(int col=0;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)return col;
    }
    return -1;
}

template<class T,class E>
int Graphmtx<T,E>::getNextNeighor(int v,int w)
{
    if(v!=-1&&w!=-1){
        for(int col=w+1;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)return col;
    }
    return -1;
}

template<class T,class E>
bool Graphmtx<T,E>::insertVertex(const T &vertex){
    if(numVertices==maxVertices)return false;
    VerticesList[numVertices++]=vertex;
    return true;
    
}

// 解释参见353
template<class T,class E>
bool Graphmtx<T,E>::removeVertex(int v){
    if(v<0||v>=numVertices)return false;
    // 图的结构可以没有边，但是要有点
    if(numVertices==1)return false;
    int i,j;
    // 将最后的一个结点转移到要删除的结点上
    VerticesList[v]=VerticesList[numVertices-1];
    for(i=0;i<numVertices;i++)
        if(Edge[i][v]>0&&Edge[i][v]<maxWeight)numEdges--;
    for(i=0;i<numVertices;i++)
        Edge[i][v]=Edge[i][numVertices-1];
    numVertices--;
    for(j=0;j<numVertices;j++)
    Edge[v][j]=Edge[numVertices][j];
    return true;
}

// 无向图的插入
template<class T,class E>
bool Graphmtx<T,E>::insertEdge(int v1,int v2,E cost){
    // 这里的if的最后的条件让无向图出现重复后权重还是原来的
    if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]==maxWeight){
        Edge[v1][v2]=Edge[v2][v1]=cost;
        numEdges++;
        return true;
    }
    else return false;
}

template<class T,class E>
bool Graphmtx<T,E>::removeEdge(int v1,int v2)
{
    if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]>0
    &&Edge[v1][v2]<maxWeight){
        Edge[v1][v2]=Edge[v2][v1]=maxWeight;
        numEdges--;
        return true;
    }
    else return false;
    
}

template<class T,class E>
istream & operator >>(istream &in,Graphmtx<T,E>&G){
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
    return in;
}

template<class T,class E>
ostream &operator <<(ostream &out,Graphmtx<T,E>&G){
    int i,j,k,n,m;
    // n为顶点数，m为边数
    T e1,e2; E weight;
    n=G.NumberOfVertices();
    m=G.NumberofEdge();
    out<<"success insert vertices and edges"<<endl;
    out<<n<<","<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
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