#include "treeNode.h"
#include <queue>

treeNode<int>* takeLevelInputs(){
    int data,n;
    cout<<"ENTER root data : ";
    cin>>data;

    treeNode<int>* root=new treeNode<int>(data);

    queue<treeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        treeNode<int>* front=q.front();
        q.pop();

        cout<<"ENTER the number of child  of"<<front->data<<":";
        cin>>n;

        for(int i=0;i<n;i++){
            cout<<"ENTER  child "<<i+1<<" of "<<front->data<<" : ";
            cin>>data;
            treeNode<int>* child=new treeNode<int>(data);
            q.push(child);
            front->children.push_back(child);
        }

    }
    return root;
}

void printLevels(treeNode<int>* root){
    queue<treeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        treeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}

treeNode<int>* takeInput(){
    int data,n;
    cout<<"ENTER data : ";
    cin>>data;

    treeNode<int>* root=new treeNode<int>(data);
    cout<<"ENTER the number of child :";
    cin>>n;

    for(int i=0;i<n;i++){
        treeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(treeNode<int>* root){
    if(root==NULL)
        return;

    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
};

// int main(){
//     // treeNode<int>* root=new treeNode<int>(1);
//     // treeNode<int>* c1=new treeNode<int>(2);
//     // treeNode<int>* c2=new treeNode<int>(3);
//     // treeNode<int>* c3=new treeNode<int>(4);
//     // treeNode<int>* c4=new treeNode<int>(5);
//     // root->children.push_back(c1);
//     // root->children.push_back(c2);
//     // root->children[0]->children.push_back(c3);
//     // root->children[0]->children.push_back(c4);
//     // treeNode<int>* root=takeInput();
//     treeNode<int>* root=takeLevelInputs();
//     // printTree(root);
//     printLevels(root);
// }