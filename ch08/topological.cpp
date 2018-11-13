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
  
int Create(node adj[],int n,int m)//�ڽӱ�������n����������m�������  
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
        cout<<"�������"<<i<<"����:";  
        int u,v;  
        cin>>u>>v;  
        p=new node;  
        p->adjvex=v;  
        p->next=adj[u].next;  
        adj[u].next=p;  
    }  
    return 1;  
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
  
void topsort(node adj[],int n)  
{  
  
    int i;  
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
    if(count<n)cout<<"�л�·"<<endl;  
}  
  
int main()  
{  
    int n;  
    int m;  
    cout<<"�����붥����������:";  
    cin>>n>>m;  
    Create(adj,n,m);  
    cout<<"������ڽӱ�Ϊ:"<<endl;  
    print(n);  
    cout<<"����������Ϊ:"<<endl;  
    topsort(adj,n);  
    system("pause");  
    return 0;  
}