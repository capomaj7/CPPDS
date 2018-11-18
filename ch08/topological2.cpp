#include<cmath>  
#include<cstdio>  
#include<algorithm>  
#include<queue>
#include<string.h>   
#include<iostream>
using namespace std;  
#define MAX 9999  
queue<int>myqueue;  
int indegree[MAX];  
  
struct node   
{  
    int adjvex;  
    node* next;  
}adj[MAX];  
  
// int Create(node adj[],int n,int m)//邻接表建表函数，n代表定点数，m代表边数  
// {  
//     int i;  
//     node *p;  
//     for(i=1;i<=n;i++)  
//     {  
          
//         adj[i].adjvex=i;  
//         adj[i].next=NULL;  
//     }  
//     for(i=1;i<=m;i++)  
//     {  
//         cout<<"请输入�?"<<i<<"条边:";  
//         int u,v;  
//         cin>>u>>v;  
//         p=new node;  
//         p->adjvex=v;  
//         p->next=adj[u].next;  
//         adj[u].next=p;  
//     }  
//     return 1;  
// }

int Create(node adj[],int n)//邻接表建表函数，n代表定点数，m代表边数  
{  
    int i;  
    node *p;  
    for(i=1;i<=n;i++)  
    {  
          
        adj[i].adjvex=i;  
        adj[i].next=NULL;  
    }  
    // for(i=1;i<=m;i++)  
    // {  
    //     cout<<"请输入�?"<<i<<"条边:";  
    //     int u,v;  
    //     cin>>u>>v;  
    //     p=new node;  
    //     p->adjvex=v;  
    //     p->next=adj[u].next;  
    //     adj[u].next=p;  
    // }  
    return 1;  
}  

// 插入边，这里不想麻烦一次�?手动输入所以定义一�?���?
void insertEdge(node adj[],int u,int v){
    node *p; 
    p=new node;  
    p->adjvex=v;  
    p->next=adj[u].next;  
    adj[u].next=p;  
} 
  
void print(int n)//邻接表打印函�?  
{  
    int i;  
    node *p;  
    for(i=1;i<=n;i++)  
    {  
        p=&adj[i];  
        while(p!=NULL)  
        {  
            cout<<p->adjvex<<" ";  
            p=p->next;  
        }  
        cout<<endl;  
    }  
}  
  
int topsort(node adj[],int n)  
{  
    int i;  
    int term=0;
    node *p;  
    // 初�?�?,将数组indegreee元素全部初�?化为0�?
    //将s�?��前位�?��面的n�?���? （typedef unsigned int size_t ）用 ch 替换并返�? s 
    memset(indegree,0,sizeof(indegree));  
    // 统�?表中的入度情�?
    for(i=1;i<=n;i++)  
    {  
  
        p=adj[i].next;  
        while(p!=NULL)  
        {  
            indegree[p->adjvex]++;  
            p=p->next;  
        }  
    }  
    // 将度�?0的放入栈�?��栈中存放的是索引
    for(i=1;i<=n;i++)  
    {  
        if(indegree[i]==0) {
            myqueue.push(i); 
            indegree[i]=-1;
        } 
             
    }  
    int count=0;
    while(myqueue.size()!=0)  
    {  
        while(myqueue.size()!=0){
        i=myqueue.front();  
        myqueue.pop();
        for(p=adj[i].next;p!=NULL;p=p->next)  
            {  
                int k=p->adjvex;  
                indegree[k]--;  
            } 
        cout<<i<<" ";  
        count++;
        }
        cout<<"|";
        term++;  
   
        for(i=1;i<=n;i++)  
        {  
    
            if(indegree[i]==0) {
                myqueue.push(i); 
                indegree[i]=-1;
            } 
                
        }  
    }  
    cout<<endl;  
    
    if(count<n){cout<<"有回�?"<<endl; return -1;}  
    return term;
}  
  
int main()  
{  
    int n;  
    int m;  
   // cout<<"请输入顶点数及边�?:";  
    //cin>>n>>m;  
    //Create(adj,n,m);  
    //cout<<"输入的邻接表�?:"<<endl;  
    Create(adj,12);
    insertEdge(adj,1,2);
    insertEdge(adj,1,3);
    insertEdge(adj,2,3);
    insertEdge(adj,1,4);
    insertEdge(adj,3,5);
    insertEdge(adj,4,5);
    insertEdge(adj,11,6);
    insertEdge(adj,3,7);
    insertEdge(adj,5,7);
    insertEdge(adj,3,8);
    insertEdge(adj,6,8);
    insertEdge(adj,9,10);
    insertEdge(adj,9,11);
    insertEdge(adj,1,12);
    insertEdge(adj,9,12);
    insertEdge(adj,10,12);
    print(12);  
    // cout<<"拓扑排序结果�?:"<<endl;  
    int termvalue=topsort(adj,12);  
    cout<<"至少需�?"<<termvalue<<"�??�?"<<endl;
    system("pause");  
    return 0;  
}