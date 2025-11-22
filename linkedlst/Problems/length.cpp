#include <iostream>
using namespace std;
#include "Node.cpp"

Node*takeInput_ef(){
    int data;
    cin>>data;

    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;

}

int count(Node* temp){
    if(temp->next==NULL)//checking the next value of the current node
        return 1;
    
    return 1+count(temp->next);//we are sending the next value of the current node
}

int ith_value(Node* temp,int i){
    int c=0;
    while(c<=i){
        temp=temp->next;
        c++;
    }
    return temp->data;
}
void print(Node* head){
    Node *temp=head; 
    //head should not be used directly
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
   
}
void insert(Node* head,int i,int data){
    int c=1;
    Node* temp =head;
    Node* newnode=new Node(data);
    while(temp!=NULL && c<i-1){
        temp=temp->next;
        c++;
    }
    //to insert the newnode
    if(temp!=NULL) 
    newnode->next=temp->next;
    temp->next=newnode;

}

int main(){
    int t,i,data;
    cout<<"Enter the required testcases: \n";
    cin>>t;
    // while(t--){
    cout<<"Enter the elements in the list: \n";
    Node* head=takeInput_ef();
    // cout<<"Enter the ith element to be found: \n";
    // cin>>i;
    // if(i>count(head)){
    //     cout<<"INVALID input";
    //     return 0;
    //     }
    // else
    // {
    //     cout<<ith_value(head,i);
    // }
    // }
    cout<<"Enter the ith location: \n";
    cin>>i;
    cout<<"Enter the data to be inserted: \n";
    cin>>data;
    insert(head,2,10);
    print(head);
}