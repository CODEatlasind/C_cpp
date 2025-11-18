#include "binarytree.h"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

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

//Contruct tree using in and pre order using lovebabar algo
int findPosition(vector<int> in,int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
        return -1;
}

binaryTreeNode<int>* Solve(vector<int> in,vector<int> pre,int instart,int inend,int &index,int n){
    if(index>=n || (instart>inend)){
        return NULL;
    }

    int element=pre[index++];
    
    cout<<"elemeny:"<<element<<endl;

    binaryTreeNode<int>* root=new binaryTreeNode<int>(element);
    int location=findPosition(in,element,n);
    
    cout<<"Loc:"<<location<<endl;
    
    root->left=Solve(in,pre,instart,location-1,index,n);
    root->right=Solve(in,pre,location+1,inend,index,n);
    return root;
}

//Contruct tree using in and pre order usinf codeingninja algo
binaryTreeNode<int>* inPre(vector<int> in,vector<int> pre,int ins,int ine,int pres,int pree){
    if(ins>ine){
        return NULL;
    }
    int rootdat=pre[pres];
    int lins=ins;
    int rootIndex=-1;
    for(int i=0;i<in.size();i++){
        if(in[i]==rootdat){
            rootIndex=i;
            break;
        }
    }
    int line=rootIndex-1;
    int lpres=pres+1;
    int lpree=line-lins+lpres;
    int rins=rootIndex+1;
    int rine=ine;
    int rpres=lpree+1;
    int rpree=pree;

    binaryTreeNode<int>* root=new binaryTreeNode<int>(rootdat);
    root->left=inPre(in,pre,lins,line,lpres,lpree);
    root->right=inPre(in,pre,rins,rine,rpres,rpree);
    return root;
}

//diameter without pair
int height(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
    
}
int diam(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left)+height(root->right),max(height(root->left),height(root->right)));
}


//diameter with pair
pair<int,int> hAndD(binaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftans=hAndD(root->left);
    pair<int,int> rightans=hAndD(root->right);
    pair<int,int> p;
    p.first=1+max(leftans.first,rightans.first);
    p.second=max(leftans.first+rightans.first,max(leftans.second,rightans.second));
    return p;
}

int main(){
    vector<int> in={4, 2, 5, 1, 6, 3, 7};
    vector<int> pre={1, 2, 4, 5, 3, 6, 7 };
    int ord=0;
    
    // binaryTreeNode<int>* root=Solve(in,pre,0,in.size(),ord,in.size());
    binaryTreeNode<int>* root=inPre(in,pre,0,in.size()-1,0,in.size()-1);
    cout<<"O/P without pair: "<<diam(root)<<endl;
    pair<int,int> hD=hAndD(root);
    cout<<hD.first<<","<<hD.second<<endl;


    printLevelBTree(root);
}