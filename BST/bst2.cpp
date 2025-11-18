#include <bits/stdc++.h>
#include <iostream>
#include "i_o_BST.h"
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head){
    Node *temp=head; 
    //head should not be used directly
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
   
}


binaryTreeNode<int>* createBst(vector<int> arr,int start, int end){
    if(arr.size()==0){
        return NULL;
    }
    
    if(start>end){
        return NULL;
    }

    int mid=start+(end-start)/2;
    binaryTreeNode<int>* root=new binaryTreeNode<int>(arr[mid]);
    root->left=createBst(arr,start,mid-1);
    root->right=createBst(arr,mid+1,end);
    return root;
}
//create a linked list in a sorted order

Node* bstToLL(binaryTreeNode<int>* root){
    if (root == NULL)
        return NULL;

    Node* leftHead=bstToLL(root->left);
    Node* temp=leftHead;

    Node* center=new Node(root->data);
    if(leftHead==NULL){
        leftHead=center;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=center;

    }
    Node* right=bstToLL(root->right);
    center->next=right;

    return leftHead;

}



// pair<int,int> bstLL(binaryTreeNode<int>* root){
//     pair<int,int> ll;
//     if(root==NULL){
//         ll.first=NULL;
//         ll.second=NULL;
            // return ll;
//     }
//     pair<int,int> leftLL=bstLL(root->left);
//     pair<int,int> rightLL=bstLL(root->right);
//     ll.first=root->data;
//     leftLL.second=ll.first;
//     ll.second=rightLL.first;
// }

//path form root to data{
vector<int>* pathFrom(binaryTreeNode<int>* root,int num){
    if(root==NULL){
        return NULL;

    }

    if(root->data==num){
        vector<int>* temp=new vector<int>();
        temp->push_back(root->data);
        return temp;
    }
    
    vector<int>* leftOut=pathFrom(root->left,num);
    if(leftOut!=NULL){
        leftOut->push_back(root->data);
        return leftOut;
    }
    vector<int>* rightOut=pathFrom(root->right,num);
    if(rightOut!=NULL){
        rightOut->push_back(root->data);
        return rightOut;
    }

    return NULL;

}


int main(){
    // vector<int> arr={1,2,3,4,5,6,7};
    // binaryTreeNode<int>* root=createBst(arr,0,arr.size()-1);
    // printLevelBTree(root);
    // binaryTreeNode<int>* root=takeLevelInput();
    // printLevelBTree(root);
    // print(bstToLL(root));
    
    binaryTreeNode<int>* root=takeLevelInput();
    vector<int>* path=pathFrom(root,2);
    for(int i=0;i<path->size();i++){
        cout<<*(path->begin()+i)<<",";
    }
    delete path;
}