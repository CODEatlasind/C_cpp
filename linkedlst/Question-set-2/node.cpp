#include <iostream>
using namespace std;
class node{
    public: 
        int data;
        node* next;

        node(int data){
            this->data=data;
            this->next=NULL;
        }
   
        node* input();
        void display(node*);
};

node* input(){
    int data;
    cout<<"ENTER the DATA:\n";
    cin>>data;

    node* head=NULL;
    node* tail=NULL;
    while(data!=-1){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{//reduce time complexity to o(n)
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void display(node* head){
    cout<<"YOUR Data:\n";
    node *temp=head; 
    
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
   
}