#include <bits/stdc++.h>
#include <iostream>
#include "binarytree.h"
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