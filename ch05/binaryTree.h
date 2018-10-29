#include<iostream>
#include<stdlib.h>
#include"../ch03/linkedStack.h"
#include"../ch03/linkedQueue.h"
using namespace std;
template<class T>
struct BinTreeNode{
    T data;
    BinTreeNode<T>*leftChild,*rightChild;
    BinTreeNode():leftChild(NULL),rightChild(NULL){}
    BinTreeNode(T x,BinTreeNode<T> *l=NULL,BinTreeNode<T> *r=NULL):data(x),leftChild(l),rightChild(r){}
};
template<class T>
class BinaryTree{
    protected:
    BinTreeNode<T>*root;
    T RefValue;
    void Destroy(BinTreeNode<T> *&subTree);
    public:
    BinaryTree():root(NULL){}
    BinaryTree(T value):RefValue(value),root(NULL){}
    BinaryTree(BinaryTree<T>&s);
    ~BinaryTree(){Destroy(root);}
    BinTreeNode<T>* CreateBinTree(BinTreeNode<T>* &subTree);
    bool IsEmpty(){return (root==NULL)?true:false;}
    BinTreeNode<T>* Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current);
    BinTreeNode<T>*LeftChild(BinTreeNode<T>*current){
        return (current!=NULL)?current ->leftChild:NULL;}
    BinTreeNode<T>*RightChild(BinTreeNode<T>*current){
        return (current!=NULL)?current ->rightChild:NULL;}
    int Height(BinTreeNode<T> *subTree)const;
    int Size(BinTreeNode<T> *subTree)const;
    BinTreeNode<T>* getRoot(){return root;}
    void setRoot(BinTreeNode<T> *subTree){ root=subTree;}
    void Traverse(BinTreeNode<T> *subTree);
    void preOrder(BinTreeNode<T> *subTree);
    void inOrder(BinTreeNode<T> *subTree);
    void postOrder(BinTreeNode<T> *subTree);
    void levelOrder();
    BinTreeNode<T>*Copy(BinTreeNode<T>*orignode);
    bool operator==(BinaryTree<T>& t);
    template<class U>
    friend istream&operator>>(istream&in,BinTreeNode<U>&Tree);
    template<class U>
    friend ostream&operator<<(ostream&os,BinTreeNode<U>&Tree);
    
};

// 注意你的原型要和定义的一样
template<class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> *&subtree){
    if(subtree!=NULL)
    {
        Destroy(subtree ->leftChild);
        Destroy(subtree ->rightChild);
        delete subtree;
    }
}
template <class T>
BinTreeNode<T>* BinaryTree<T>::CreateBinTree(BinTreeNode<T>* &subTree)
{
    T item;
    // subTree=root;
    cin >> item;
    if (item != RefValue)
    {
        subTree = new BinTreeNode<T>(item);
        if (subTree == NULL)
        {
            cerr << "error" << endl;
            exit(1);
        }
        CreateBinTree(subTree ->leftChild);
        CreateBinTree(subTree ->rightChild);
    }
    else
    {
        subTree = NULL;
    }
    return subTree;
}
// 返回父结点 
template<class T>
BinTreeNode<T> * BinaryTree<T>::Parent(BinTreeNode<T>*subTree,BinTreeNode<T>*current){
    if(subTree==NULL)return NULL;
    if(subTree ->leftChild==current||subTree ->rightChild==current)return subTree;
    BinTreeNode<T>*p;
    //左子树遍历
    if((p=Parent(subTree ->leftChild,current))!=NULL)return p;
    // 右子树遍历
    else return Parent(subTree ->rightChild,current);
}

// 先序遍历输出
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree){
    if(subTree!=NULL){
        cout<<subTree ->data<<'\t';
        Traverse(subTree ->leftChild);
        Traverse(subTree ->rightChild);
    }   
}


// 建立一个二叉树,重载输入运算符
template<class T>
istream &operator>>(istream &in,BinaryTree<T>&tree){
    // CreateBinTree(in,Tree.getRoot());
    BinTreeNode<T> *p;
    tree.CreateBinTree(p);
    tree.setRoot(p);
    return in;
}

template<class T>
ostream &operator<<(ostream &out,BinaryTree<T> &tree){
    out<<"preOrder is:\n";
    tree.Traverse(tree.getRoot());
    out<<endl;
    return out;
}

// 输入广义表的形式建立二叉树的算法,见树p197
template<class T>
void CreateBinTreeWithTable(BinTreeNode<T>*&Tree,T RefValue){
    LinkedStack<BinTreeNode<T> *> s;
    Tree=NULL;
    BinTreeNode<T>*p,*t;int k;
    T ch;
    cin >>ch;
    while(ch!=RefValue)
    {
        switch(ch){
            case'(':s.Push(p);k=1;break;
            case')':s.Pop(t);break;
            case',':k=2;break;
            default:
            p=new BinTreeNode<T>(ch);
            if(Tree==NULL)Tree=p;
            else if(k==1){
                s.getTop(t);
                t ->leftChild=p;
            }
            else{
                s.getTop(t);
                t ->rightChild=p;
            }
        }
        cin>>ch;
    }
}

// 递归遍历前中后序的树
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>*subTree)
{
    if(subTree!=NULL)
    {
        inOrder(subTree ->leftChild);
        cout<<subTree ->data<<"\t";
        inOrder(subTree ->rightChild);
    }
}

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>*subTree){
    if(subTree!=NULL){
        cout<<subTree ->data<<" ";
        preOrder(subTree ->leftChild);
        preOrder(subTree ->rightChild);
    }
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *subTree)
{
    if(subTree!=NULL){
        postOrder(subTree ->leftChild);
        postOrder(subTree ->rightChild);
        cout<<subTree ->data<<"\t";
    }
}

template<class T>
void BinaryTree<T>::levelOrder(){
    LinkedQueue<BinTreeNode<T>*>Q;
    BinTreeNode<T>*p=root;
    Q.EnQueue(p);
    while(!Q.IsEmpty()){
        Q.DeQueue(p);
        cout<<p->data<<"\t";
        if(p ->leftChild) Q.EnQueue(p ->leftChild);
        if(p ->rightChild)Q.EnQueue(p ->rightChild);
    }
}
// 返回的结点数
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)const{
    if(subTree==NULL)return 0;
    else return 1+Size(subTree ->leftChild)+Size(subTree ->rightChild);
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)const{
    if(subTree==NULL)return 0;
    else{
        int i=Height(subTree ->leftChild);
        int j=Height(subTree ->rightChild);
        return (i<j)?j+1:i+1;
    }
    
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>&s){
    root=Copy(s.root);
    RefValue=s.RefValue;
}

// 递归拷贝二叉树的副本
template<class T> 
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T>*orignode){
    if(orignode==NULL)return NULL;
    BinTreeNode<T>*temp=new BinTreeNode<T>;
    temp ->data= orignode ->data;
    temp ->leftChild=Copy(orignode ->leftChild);
    temp ->rightChild=Copy(orignode ->rightChild);
    return temp;
}
template<class T>
bool equal(BinTreeNode<T>*a,BinTreeNode<T>*b){
    if(a==NULL&&b==NULL)return true;
    if(a!=NULL&&b!=NULL&&a ->data==b ->data&&
        equal(a ->leftChild,b ->leftChild)&&
        equal(a ->rightChild,b ->rightChild))
        return true;
    return false;
}

// 注意这里==重载可以不用友元函数，不需要2个
template<class T>
bool BinaryTree<T>::operator==(BinaryTree<T>&s){
    return equal(this->root,s.getRoot())?true:false;
}




// 以广义表的形式输出二叉树
template<class T>
void PrintBTreeWithTable(BinTreeNode<T> *tree){
    if(tree!=NULL)
    {
        cout<<tree ->data;
        if(tree ->leftChild!=NULL||tree ->rightChild!=NULL)
        {
            cout<<"(";
            PrintBTreeWithTable(tree ->leftChild);
            cout<<",";
            // if(tree ->rightChild)
            PrintBTreeWithTable(tree ->rightChild);
            cout<<")";
        }
    }
}

// 这个是退栈的时候访问，放出来审问类型
//元素进去后，放出来后审问问你要右结点，有放进栈，再问你左结点，有放进去,直到穷尽
template<class T>
void preOrder2(BinTreeNode<T>*tree)
{
    LinkedStack<BinTreeNode<T>*>s;
    BinTreeNode<T>*p=tree;
    s.Push(p);
    while(!s.IsEmpty()){
        s.Pop(p);
        cout<<p ->data<<"\t";
        // 注意这里一定要先进右边，注意这边是先进2个出一个的套路
        if(p ->rightChild!=NULL)s.Push(p ->rightChild);
        if(p ->leftChild!=NULL)s.Push(p ->leftChild);
    }
}

// 这个是进栈的时候访问，进去之前访问类型
// 先访问（输出）,然后询问有不有右结点，有放进去，
// 继续询问有不有左结点，根据提供线索去查找左结点,有的话访问,没有将栈中放出去的元素看看有不有左右结点
template<class T>
void preOrder3(BinTreeNode<T>*tree){
    LinkedStack<BinTreeNode<T>*>s;
    BinTreeNode<T>*p=tree;
    s.Push(NULL);
    while(p){
       cout<<p ->data<<"\t";
        if(p ->rightChild)s.Push(p ->rightChild);
        // 没有左子树就要输出
        if(p ->leftChild)p=p ->leftChild;
        else
        s.Pop(p);
    }
}

// 经典的中序遍历(没放出一个都要询问有不有右结点)
// 这里一股脑将左结点都放进去,都进去后直至没有左结点
// 放出一个后审问并问有不有右结点,有放入并将其左结点全放入
// 若左右结点都没有,继续放人,审问右结点
template<class T>
void inOrder2(BinTreeNode<T> *tree,void(*visit)(BinTreeNode<T>*p)){
    LinkedStack<BinTreeNode<T>*>s;
    BinTreeNode<T>*p=tree;
    do{
        // 现将左孩子都遍历放进去
        while(p)
        {
            s.Push(p);
            p=p ->leftChild;
        }
        if(!s.IsEmpty()){
            s.Pop(p);
            cout<<p ->data<<"\t";
            // 遍历指针进入到右边子女结点
            p =p ->rightChild;
        }
    }while(p||!s.IsEmpty());
}

// // 后序遍历需要做标记,左右子树都遍历之后才访问根节点,所以要标记是访问是左子树还是有子树
// // 栈结点标记
template<class T>
struct stkNode{
    BinTreeNode<T>*ptr;
    char tag;
    stkNode(BinTreeNode<T>*N=NULL):ptr(N),tag('L'){};
};
template<class T>
void postOrder2(BinTreeNode<T>*tree,void(*visit)(BinTreeNode<T>*p)){
    LinkedStack< stkNode<T> >s;
    stkNode<T>w;
    BinTreeNode<T> *p=tree;
    do{
        while(p)
        {
            w.ptr=p;
            w.tag='L';
            s.Push(w);
            p=p ->leftChild;

        }
        // 继续循环的标记
        int continuel=1;
        while(continuel&&!s.IsEmpty()){
            s.Pop(w);
            p=w.ptr;
            switch(w.tag)
            {
                case 'L':w.tag='R';
                s.Push(w);
                continuel=0;
                p=p ->rightChild;
                break;
                case 'R':visit(p);break;
            }
        }
    }while(!s.IsEmpty());
    cout<<endl;
}


