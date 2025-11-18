#include "binarytree.h"
#include <iostream>
#include <queue>

using namespace std;

binaryTreeNode<int>* takeLevelInput(){
    int rootdat;
    cout<<"ENTER Root Data : ";
    cin>>rootdat;
    if(rootdat==-1)
        return NULL;

    binaryTreeNode<int>* root=new binaryTreeNode<int>(rootdat);
    queue<binaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
    
        binaryTreeNode<int>* front=q.front();
        q.pop();

        int leftdat,rightdat;
        //leftchild
        cout<<"ENTER left child Data of "<<front->data<<" : ";
        cin>>leftdat;
        if(leftdat!=-1){
            binaryTreeNode<int>* child=new binaryTreeNode<int>(leftdat);
            front->left=child;
            q.push(child);
        }
        cout<<endl;
        //right child
        cout<<"ENTER right child Data of "<<front->data<<" : ";
        cin>>rightdat;
        if(rightdat!=-1){
            binaryTreeNode<int>* child=new binaryTreeNode<int>(rightdat);
            front->right=child;
            q.push(child);
        }
    cout<<endl;
    }
        return root;


}

binaryTreeNode<int>* takeInput(){
    int rootdat;
    cout<<"ENTER Data : ";
    cin>>rootdat;
    binaryTreeNode<int>* root;

    if(rootdat==-1)
        return NULL;
    else
        root=new binaryTreeNode<int>(rootdat);
    
    
    
    cout<<"ENTER the left child of "<<root->data<<" element : "<<endl;
    root->left=takeInput();
    cout<<"ENTER the right child of "<<root->data<<" element : "<<endl;
    root->right=takeInput();
    return root;
}

void printLevelBTree(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    
    queue<binaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        binaryTreeNode<int>* front=q.front();
        q.pop();
        
        cout<<front->data<<":";
        
        if(front->left!=NULL){
            cout<<"L "<<front->left->data<<" ";
            q.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R "<<front->right->data<<" ";
            q.push(front->right);
        }

        cout<<endl;
    }
}

void printBTree(binaryTreeNode<int>* root){
    
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L "<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R "<<root->right->data<<" ";
    }
    cout<<endl;

    printBTree(root->left);
    printBTree(root->right);
    
}
int count(binaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    return 1+count(root->left)+count(root->right);
}

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
    // binaryTreeNode<int>* root=new binaryTreeNode<int>(1);
    // binaryTreeNode<int>* n1=new binaryTreeNode<int>(2);
    // binaryTreeNode<int>* n2=new binaryTreeNode<int>(3);
    // root->left=n1;
    // root->right=n2;
    // cout<<root->data<<","<<root->left->data<<","<<root->right->data;

    // binaryTreeNode<int>* root=takeInput();
    //  binaryTreeNode<int>* root=takeLevelInput();
    // // printBTree(root);
    // printLevelBTree(root);
    // cout<<endl;
    // cout<<count(root);
    //  binaryTreeNode<int>* root=takeLevelInput();
    // printLevelBTree(root);
    // root=mirror(root);
    // 8  7 10 5 6 -1 -1 2 -1 -1 -1 -1 -1
    binaryTreeNode<int>* root=takeLevelInput();
    
    printLevelBTree(root);
    

    delete root;
}