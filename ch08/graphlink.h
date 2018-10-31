#include<iostream>
#include<stdlib.h>
#ifndef _GRAPHLINK_H_
#define _GRAPHLINK_H_
using namespace std;
const int DefaultVertices=30;
const int maxWeight=1024;
template<class T,class E>
//边结点的定义
struct Edge{
    // 定义下个结点所在的位置
    int dest;
    // 权重
    E cost;
    Edge <T,E> *link;
    Edge(){}
    Edge(int num,E weigh):dest(num),cost(weigh),link(NULL){}
    bool operator !=(Edge <T,E> &R)const{
        return (dest!=R.dest)?true:false;
    }

};

template<class T,class E>
struct Vertex{
    // 放顶点信息的
    T data;
    // 放指向边结点的
    Edge <T,E> *adj;
};

template<class T,class E>
class Graphlink{
    template<class M,class N>
    friend istream & operator >>(istream &in,Graphlink<M,N>&G);
    template<class M,class N>
    friend ostream & operator <<(ostream &out,Graphlink<M,N>&G);
    private:
      int maxVertices;
      int numEdges;
      int numVertices;
      Vertex<T, E> *NodeTable;
      int getVertexPos(const T Vertex)
      {
          for (int i = 0; i < numVertices;i++)
          {
              if(NodeTable[i].data==Vertex)return i;
          }
          return -1;
    }
    public:
    Graphlink(int sz =DefaultVertices);
    ~Graphlink();
    T getValue(int i){return (i>=0&&i<numVertices)?NodeTable[i].data:0;}
    E getWeight(int v1,int v2);
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
Graphlink<T,E>::Graphlink(int sz){
    maxVertices=sz;
    numVertices=0; numEdges=0;
    NodeTable =new Vertex <T,E>[maxVertices];
    if(NodeTable==NULL){cerr<<"error"<<endl;exit(1);}
    for(int i=0;i<maxVertices;i++) NodeTable[i].adj=NULL;
}
template<class T,class E>
Graphlink<T,E>::~Graphlink(){
    for(int i=0;i<numVertices;i++)
    {
        Edge <T,E> *p=NodeTable[i].adj;
        while(p)
        {
            NodeTable[i].adj=p ->link;
            delete p;
            p=NodeTable[i].adj;
        }
    }
    delete [] NodeTable;
}

template<class T,class E>
int Graphlink<T,E>::getFirstNeighbor(int v)
{
    if(v!=-1)
    {
        Edge <T,E> *p=NodeTable[v].adj;
        if(p) return p ->data;
    }
    return -1;
}

template<class T,class E>
int Graphlink<T,E>::getNextNeighor(int v,int w)
{
    if(v!=-1)
    {
        Edge <T,E> *p=NodeTable[v].adj;
        while(p&&p->dest!=w)
            p=p ->link;
        if(p&&p ->link)
        return p ->link ->dest;
    }
    return -1;
}

template<class T,class E>
E Graphlink<T,E>::getWeight(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
    {
        Edge <T,E> *p=NodeTable[v1].adj;
        while(p&&p->dest !=v2)
        {
            p =p ->link;
        }
        if(p) return p ->cost;
    }
     return 0;

}

template<class T,class E>
bool Graphlink<T,E>::insertVertex(const T& vertex){
    if(numVertices==maxVertices)return false;
    NodeTable[numVertices].data=vertex;
    numVertices++; return true;
}
// 消除行就行了吧，但是为什么要有那么多其他的操作
// 因为除了把点消除了之外还要把和他有关系的边消除了
// c++要严谨缜密
template<class T,class E>
bool Graphlink<T,E>::removeVertex(int v){
    if(numVertices==1||v<0||v>=numVertices)return false;
    // p是指向要删除表上的结点
    // s是他关联的结点上的结点
    // t是他管理结点上的结点的前驱
    Edge <T,E> *p,*s,*t;
    int i,k;
    // cout<<"nihao"<<endl;
    while(NodeTable[v].adj)
    {
        p=NodeTable[v].adj;
        k =p ->dest;
        s=NodeTable[k].adj;
        // t指针是s指针的前驱
        t=NULL;
        // 找出和他相关的连的v结点
        while(s&&s ->dest!=v)
        {
            t=s;
            s =s ->link;
        }
        if(s){
            // 这里不明白t为什么等于空
            // 为什么等于空时应为s第一个结点就是v所以不会进入循环了
            // 所以只要将后移指针就好
            if(t==NULL)NodeTable[k].adj=s ->link;
            // 删除s结点的的操作，因为之前t指针是s指针的前驱
            else t ->link=s ->link;
            delete s;
        }
        // 结束了一个结点了，继续下一个结点的循环
        NodeTable[v].adj=p ->link;
        delete p;
        numEdges--;
    }
    numVertices--;
    // 用最后一个来填补新的一个,注意这里已经在上面做过--自减操作了
    NodeTable[v].data =NodeTable[numVertices].data;
    NodeTable[v].adj=NodeTable[numVertices].adj;
    p=NodeTable[v].adj;
    // cout<<p ->cost<<endl;
    while(p){
        s=NodeTable[p ->dest].adj;
        // 因为这里没删除的操作，所以没有使用前驱指针
        while(s){
            if(s ->dest==(numVertices)){s ->dest=v;break;}
            else s=s ->link;
        }
        p =p ->link;
    }
    // cout<<"nihao3"<<endl;
    return true;
}

// 这里是无向图的插入
template<class T,class E>
bool Graphlink<T,E>::insertEdge(int v1, int v2,E weight){
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices)
    {
        Edge <T,E> *q,*p= NodeTable[v1].adj;
        while(p&&p ->dest!=v2)
            p =p ->link;
        // 因为要插入，看看是不是已存在这个边，如果存在，就不插入了
        if(p)return false;
        p=new Edge <T,E>;
        q =new Edge <T,E>;
        p ->dest=v2;
        p ->cost=weight;
        p ->link=NodeTable[v1].adj;
        NodeTable[v1].adj=p;
        q ->dest=v1;
        q ->cost=weight;
        q ->link=NodeTable[v2].adj;
        NodeTable[v2].adj=q; //这里复制的时候没有更改好
        numEdges++;
        return true;
        
    }
    return false;
}

// 删除边的思路是类似链表删除结点，这里要用它的前驱
template<class T,class E>
bool Graphlink<T,E>::removeEdge(int v1,int v2){
    if(v1!=-1&&v2!=-1){

        Edge <T,E>*p= NodeTable[v1].adj,*q=NULL,*s=p;
        while(p&&p ->dest!=v2) {q=p;p =p ->link;}
        if(p){
            // 如果p就是边链表的首个结点，就直接删除
            if(p==s)NodeTable[v1].adj=p ->link;
            else q ->link=p ->link;
            delete p;

        }else return false;
        p=NodeTable[v2].adj;
        q=NULL;
        s=p;
         while(p&&p ->dest!=v1) {q=p;p =p ->link;}
        if(p){
            // 如果p就是边链表的首个结点，就直接删除
            if(p==s)NodeTable[v2].adj=p ->link;
            else q ->link=p ->link;
            delete p;
            numEdges--;
            return true;
        }
         return false;

    }
}

template<class T,class E>
istream & operator >>(istream &in,Graphlink<T,E>&G){
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
            cout<<"errer,not exsit vertex that you enter,check it"<<endl;    
        }else{
            G.insertEdge(j,k,weight);
            i++;
        }
    }
   cout<<"success insert vertices and edges"<<endl;
    return in;
}

template<class T,class E>
ostream &operator <<(ostream &out,Graphlink<T,E>&G){
    int i,j,k,n,m;
    // n为顶点数，m为边数
    T e1,e2; E weight;
    n=G.NumberOfVertices();
    m=G.NumberofEdge();
    out<<"vertices and edges num:";
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

#endif