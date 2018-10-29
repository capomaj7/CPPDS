#include<iostream>
#include"binaryTree.h"
using namespace std;

void visitTree(BinTreeNode<char>*p){
    cout<<p ->data<<"\t";
}
// 测试
int main(int argc, char const *argv[])
{
    
    BinaryTree <char> tree('#');
    BinTreeNode<char> *p;
    // 广义表的创建 测试用例  a(b(d,e(g,)),c(,f))#
    // CreateBinTreeWithTable(p,'#');
    // tree.setRoot(p);
    // tree.preOrder(tree.getRoot());

    // 正常的创建
    // tree.CreateBinTree(p);
    // tree.setRoot(p);
    // // tree.preOrder(tree.getRoot());
    // tree.Traverse(tree.getRoot());
    // 用重载构造直接创建
    cin>>tree;
    cout<<tree<<endl;
    // 递归先序
    // tree.preOrder(tree.getRoot());
    // 递归中序
    // tree.inOrder(tree.getRoot());
    // 递归后序
    // tree.postOrder(tree.getRoot());
    // 层遍历
    //tree.levelOrder();
    // 结点数
    // int treeSize=tree.Size(tree.getRoot());
    // cout<<endl<<treeSize;
    // 高度
    // int heightTree=tree.Height(tree.getRoot());
    // cout<<heightTree<<endl;
    // 复制构造函数
    // BinaryTree <char> tree2(tree);
    // cout<<tree2;
    // BinaryTree <char> tree2('#');
    // cout<<"input tree2"<<endl;
    // cin>>tree2;
    // cout<<(equal(tree.getRoot(),tree2.getRoot()))<<endl;
    // cout<<(tree==tree2)<<endl;
    // 广义表的形式输出
    // PrintBTreeWithTable(tree.getRoot());
    // preOrder3(tree.getRoot());
    // 非递归中序遍历,后面外带的是固定的函数，不带模板T
    // inOrder2(tree.getRoot(),visitTree);
    // 非递归后序遍历
    // postOrder2(tree.getRoot(),visitTree);

    // 父节点的实验 ab#c##e##,选c点为子节点，父结点是b
    // BinTreeNode<char> *son=tree.getRoot() ->leftChild ->rightChild;
    // BinTreeNode<char> *parent1;
    // parent1=tree.Parent(tree.getRoot(),son);
    // cout<<parent1 ->data<<endl;
    return 0;
    // ab##c##
}