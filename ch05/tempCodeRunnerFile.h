template<class T>
void PrintBTree(BinTreeNode<T> *tree){
    if( tree!=NULL)
    {
        cout<< tree ->data;
        if(tree ->leftChild!=NULL||tree ->rightChild!=NULL)
        {
            cout<<"(";
            PrintBTree(tree ->leftChild);
            cout<<",";
            // if(tree ->rightChild)
            PrintBTree(tree ->rightChild);
            cout<<")";
        }
    }
}