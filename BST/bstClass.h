#include "i_o_BST.h"

class BST {
binaryTreeNode<int>* root;

private:
bool searchBst( binaryTreeNode<int>* root, int data){
    if(root==NULL){
        return false;
    }

    if( root->data==data){
        return true;
    }
    else if(data<root->data){
        return (searchBst(root->left,data));
    }
    else if(data>root->data){
        return (searchBst(root->right,data));
    }
}

binaryTreeNode<int>* insertBst(binaryTreeNode<int>* root,int data){
    if( root == NULL ){
        binaryTreeNode<int>* temp=new binaryTreeNode<int>(data);
        return temp;
    }

    if(data<root->data){
        root->left = insertBst(root->left,data);
    }
    else if(data>root->data){
        root->right = insertBst(root->right,data);
    }
}
binaryTreeNode<int>* smallest(binaryTreeNode<int>* root){
    binaryTreeNode<int>* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

binaryTreeNode<int>* cases(binaryTreeNode<int>* root){
    binaryTreeNode<int>* temp=root;
    if(root->left==NULL && root->right==NULL){
        root=NULL;
    }
    else if(root->left==NULL && root->right!=NULL ){
        root=root->right;
    }
    else if(root->left!=NULL && root->right==NULL ){
        root=root->left;
    }
    else if(root->right!=NULL && root->left!=NULL){
        
        root=smallest(root->right);
        
    }   
        delete temp;
}
binaryTreeNode<int>* deleteBst(binaryTreeNode<int>* root,int data){
    binaryTreeNode<int>* temp=root;

    if(root==NULL){
        return NULL;
    }
    if( data<root->data){
        temp=deleteBst(root->left,data);
    }
    else if(data>root->data){
        temp=deleteBst(root->right,data);
    }
    else{
        temp=cases(root);
    }
    return temp;
}
public:
void createTree(){
    root=takeLevelInput();
}
void printBst(){
    printLevelBTree(root);
}
BST(){
    root=NULL;
}
~BST(){
    delete root;
}

bool searchBst(int data){
    return searchBst(root,data);
}
void insertBst(int data){
    root = insertBst(root,data);
}
void deleteBst(int data){
    if(searchBst(data)==false){
        cout<<"Data Not in tree"<<endl;
        return;
    }
    binaryTreeNode<int>* temp= deleteBst(root,data);

}


};

