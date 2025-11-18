#include "binaryTreeUse.cpp"
#include <iostream>
using namespace std;

binaryTreeNode<int>* mirror(binaryTreeNode<int>* root){
    if(root==NULL)
        return NULL;

        binaryTreeNode<int>* temp=mirror(root->left);
        binaryTreeNode<int>* l=mirror(root->right);
        binaryTreeNode<int>* r=temp;
        root->left=l;
        root->right=r;
}
int main(){
    binaryTreeNode<int>* root=takeLevelInput();
    printLevelBTree(root);
    root=mirror(root);
    printLevelBTree(root);
    
}