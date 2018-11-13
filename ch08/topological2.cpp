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
  
// int Create(node adj[],int n,int m)//�ڽӱ�������n����������m�������  
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
//         cout<<"�������"<<i<<"����:";  
//         int u,v;  
//         cin>>u>>v;  
//         p=new node;  
//         p->adjvex=v;  
//         p->next=adj[u].next;  
//         adj[u].next=p;  
//     }  
//     return 1;  
// }

int Create(node adj[],int n)//�ڽӱ�������n����������m�������  
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
    //     cout<<"�������"<<i<<"����:";  
    //     int u,v;  
    //     cin>>u>>v;  
    //     p=new node;  
    //     p->adjvex=v;  
    //     p->next=adj[u].next;  
    //     adj[u].next=p;  
    // }  
    return 1;  
}  

// ����ߣ����ﲻ���鷳һ�δ��ֶ��������Զ���һ������
void insertEdge(node adj[],int u,int v){
    node *p; 
    p=new node;  
    p->adjvex=v;  
    p->next=adj[u].next;  
    adj[u].next=p;  
} 
  
void print(int n)//�ڽӱ��ӡ����  
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
    // ��ʼ��,������indegreeeԪ��ȫ����ʼ��Ϊ0��
    //��s�е�ǰλ�ú����n���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s 
    memset(indegree,0,sizeof(indegree));  
    // ͳ�Ʊ��е�������
    for(i=1;i<=n;i++)  
    {  
  
        p=adj[i].next;  
        while(p!=NULL)  
        {  
            indegree[p->adjvex]++;  
            p=p->next;  
        }  
    }  
    // ����Ϊ0�ķ���ջ�У�ջ�д�ŵ�������
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
    
    if(count<n){cout<<"�л�·"<<endl; return -1;}  
    return term;
}  
  
int main()  
{  
    int n;  
    int m;  
   // cout<<"�����붥����������:";  
    //cin>>n>>m;  
    //Create(adj,n,m);  
    //cout<<"������ڽӱ�Ϊ:"<<endl;  
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
    // cout<<"����������Ϊ:"<<endl;  
    int termvalue=topsort(adj,12);  
    cout<<"������Ҫ"<<termvalue<<"��ѧ��"<<endl;
    system("pause");  
    return 0;  
}