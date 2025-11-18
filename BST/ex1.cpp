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
//Search in binary search tree
bool searchBT(binaryTreeNode<int>* root,int a){
    if(root==NULL){
        return false;
    }
    if(root->data==a){
        return true;
    }
    if(a>root->data){
        searchBT(root->right,a);
    }
    else{
        searchBT(root->left,a);
    }
}
//to print elements within the range
void rangeBW(binaryTreeNode<int>* root,int min, int max){
    
    if(root==NULL){
        return ;
    }
    if(root->data>=min)
    {
        rangeBW(root->left,min,max);
    }

    if(root->data>=min && root->data<=max)
        cout<<root->data<<endl;

    if(root->data<=max)
    {
        rangeBW(root->right,min,max);
    }
    
}

//Crete a vector which stores the note data between a range of min & max
void rangeBWVec(binaryTreeNode<int>* root,int min, int max,vector<int>& re){
    
    
    if(root==NULL){

        return;
    }
    if(root->data>=min)
    {
        rangeBWVec(root->left,min,max, re);
    }

    if(root->data>=min && root->data<=max)
        re.emplace_back(root->data);

    if(root->data<=max)
    {
        rangeBWVec(root->right,min,max, re);
    }
    
}

int maxium(binaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maxium(root->left),maxium(root->right)));
}
int minium(binaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minium(root->left),minium(root->right)));
}
bool checkBst(binaryTreeNode<int>* root){
    if( root ==NULL){
        return true;
    }
    int leftmax=maxium(root->left);
    int rightmin=minium(root->right);

    return (root->data>leftmax && root->data<rightmin && checkBst(root->left) && checkBst(root->right));
}
bool chekckBst2(binaryTreeNode<int >* root, int min=INT_MIN , int max=INT_MAX){
    if( root==NULL ){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool leftis=chekckBst2(root->left, min, root->data-1);
    bool rightis=chekckBst2(root->right, root->data,max);
    return leftis && rightis;
}

int main(){
    // 8 6 10 5 7 -1 -1 2 -1 -1 -1 -1 -1
    binaryTreeNode<int>* root=takeLevelInput();
    // printLevelBTree(root);
    // cout<<searchBT(root, 10);

//     vector<int> ans;
//     rangeBWVec(root,6,10,ans);
//     // Sorting is NlogN
//     sort(ans.begin(),ans.end());
// for(auto it:ans){
//     cout<<it<<endl;
// }

    string n=checkBst(root) ? "true" : "false";
    string n2=chekckBst2(root) ? "true" : "false";
    cout<< n <<" "<<n2 <<endl;
    
}