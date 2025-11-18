#include "node.cpp"

node* midpoint(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;//Move at half the speed of fast
        fast=fast->next->next;//Moves at twice the speed compared to slow
    }
    return slow;
}

node* reversell(node* head){
    if(head->next==NULL || head==NULL){
        return head;
        
    }

    node* hnew=reversell(head->next);

    node* temp=hnew;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=head;
    head->next=NULL;
    return hnew;
}

int main(){
    node* head=input();
    //find Midpoint
    /*node* mid = midpoint(head);
    cout<<mid->data;*/

    //reverse recursively
    head=reversell(head);
    display(head);
    

}