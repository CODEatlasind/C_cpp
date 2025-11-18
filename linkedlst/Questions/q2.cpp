#include <iostream>
#include "node.cpp"
using namespace std;

int count(node* temp){
    if(temp->next==NULL)
        return 1;
    
    return 1+count(temp->next);
}
void merge(node* h1,node* h2){
    node* tail=h1;
    int c=0;
    int len=count(h1);
    while(c<len-1){
        tail=tail->next;
        c++;
    }
    tail->next=h2;
}

node* put(node* head,int n){
    
    int len = count(head);
    int c=1;
     node* temp=head;
    
    
    while(c<(len-n)){
        temp=temp->next;
        c++;
    }
    node* h2=temp->next;
    temp->next=NULL;
    node*x=h2;
    merge(h2,head);
    return h2;
}
void remove_duplicates(node* head){
    node* t1=head;
    node* t2=head->next;
    if(head==nullptr){
        return;
    }
    while(t2!=NULL){
        if(t1->data==t2->data){
            node* temp=t2;
            t2=t2->next;
            delete temp;
        }
        else{
            t1->next=t2;
            t1=t1->next;
            t2=t2->next;
        }
            
    }
    t1->next=t2;
}

node* reverse(node* head){
        node* prev=head;
        node* curr=head;
        node* next2=head->next;
        while(curr!=NULL){
            next2=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next2;
        }
        head->next=NULL;
        head=prev;
            return head;
}

int pallindrome(node* head){
    int len=count(head),c=1;
    int divider;
    node* temp=head;
    if(len%2==0){
        divider=len/2;
    }
    else
        divider=len/2+1;
    
    while (c<divider)
    {
        temp=temp->next;
        c++;
    }
    node* h2=temp->next;
    temp->next=NULL;

    h2=reverse(h2);
    
    node* temp1=head;
    node* temp2=h2;
    display(temp1);
    cout<<"\n";
    display(temp2);
    c=1;
    while ( temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            c=0;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return c;
        
}

int main(){
    cout<<"ENTER the elements\n";
    node* head=input();
    //to bring the n last elements of a list to front
    /*int n;
    cout<<"ENTER n\n";
    cin>>n;
    node* h2=put(head,n);
    display(h2);*/
    
    //REMOVE DUPLOICATES
    /*cout<<"list without duplicates are:\n" ;
    remove_duplicates(head);*/
    
    if(pallindrome(head)==1)
        cout<<"TRUE";
    else
        cout<<"FALSE";
}