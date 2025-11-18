#include<iostream>
#include "node.cpp"

using namespace std;

int find(node *head, int x){
    if(head==NULL)
    return -1;

    if(head->data==x){
        return 0;
    }
    return 1+find(head->next,x);
}

int main(){
    cout<<"Take Input:\n";
    node* head=input();
    cout<<"LIST:\n";
    display(head);

    int x;
    cout<<"\n Data to be found:\n";
    cin>>x;
    cout<<"Index:\n";
    cout<<find(head,x);


    
}