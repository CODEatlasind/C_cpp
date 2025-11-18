#include "node.cpp"

node* merge(node* h1,node* h2){
    node* head=NULL;
    node* tail=NULL;
    if(h1==NULL && h2==NULL){
        return NULL;
    }
    else if(h1!=NULL && h2==NULL ){
        return h1;
    }
    else {
        return h2;
    }

    if(h1->data<h2->data){
        head = h1;
        tail=h1;
        h1=h1->next;
    }
    else{
        head = h2;
        tail=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL){
        if(h2->data<h1->data){
            tail->next=h2;
            h2=h2->next;
        }
        else{
            tail->next=h1;
            h1=h1->next;
        }
    }
    if(h1==NULL){
        tail->next=h2;
    }
    else{
        tail->next=h1;
    }
    return head;

}

int main(){
    node* h1=input();
    node* h2=input();
    node *head=merge(h1,h2);
    display(head);
}