#include<cmath>  
#include<cstdio>  
#include<algorithm>  
#include<stack>  
#include<string.h>   
#include<iostream>
using namespace std;  
#define MAX 9999  
//https://blog.csdn.net/a20180825/article/details/76718465
stack<int>mystack;  
int indegree[MAX];  
  
struct node   
{  
    int adjvex;  
    node* next;  
}adj[MAX];  
  
int Create(node adj[],int n,int m)//邻接表建表函数，n代表定点数，m代表边数  
{  
    int i;  
    node *p;  
    for(i=1;i<=n;i++)  
    {  
          
        adj[i].adjvex=i;  
        adj[i].next=NULL;  
    }  
    for(i=1;i<=m;i++)  
    {  
        cout<<"请输入第"<<i<<"条边:";  
        int u,v;  
        cin>>u>>v;  
        p=new node;  
        p->adjvex=v;  
        p->next=adj[u].next;  
        adj[u].next=p;  
    }  
    return 1;  
}  
  
  
void print(int n)//邻接表打印函数  
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
  
void topsort(node adj[],int n)  
{  
  
    int i;  
    node *p;  
    // 初始化,将数组indegreee元素全部初始化为0，
    //将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 
    memset(indegree,0,sizeof(indegree));  
    // 统计表中的入度情况
    for(i=1;i<=n;i++)  
    {  
  
        p=adj[i].next;  
        while(p!=NULL)  
        {  
            indegree[p->adjvex]++;  
            p=p->next;  
        }  
    }  
    // 将度为0的放入栈中，栈中存放的是索引
    for(i=1;i<=n;i++)  
    {  
  
        if(indegree[i]==0) 
            mystack.push(i); 
             
    }  
    int count=0;   
    while(mystack.size()!=0)  
    {  
  
        i=mystack.top();  
        mystack.pop();  
        cout<<i<<" ";  
        count++;  
        for(p=adj[i].next;p!=NULL;p=p->next)  
        {  
            int k=p->adjvex;  
            indegree[k]--;  
            if(indegree[k]==0)  
                mystack.push(k);  
        }  
    }  
    cout<<endl;  
    if(count<n)cout<<"有回路"<<endl;  
}  
  
int main()  
{  
    int n;  
    int m;  
    cout<<"请输入顶点数及边数:";  
    cin>>n>>m;  
    Create(adj,n,m);  
    cout<<"输入的邻接表为:"<<endl;  
    print(n);  
    cout<<"拓扑排序结果为:"<<endl;  
    topsort(adj,n);  
    system("pause");  
    return 0;  
}