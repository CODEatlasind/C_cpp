#include <iostream>
using namespace std;
#include "Node.cpp"
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=nullptr;
    while(data!=-1){
        Node* newnode=new Node(data);//with static it got erased everytime a new node was created

        if(head==nullptr){
            //to prevent complete traversal while taking input and inexchange bringing head to the last point
            head=newnode;
            }//its a pointer to the node so no &
        else{/* time complexity is O(n^2) as loop has to travel the entire linked list*/
            Node* temp=head;//else the head would have been allocated to the next block
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }

        cin>>data;
    }
    return head;
}
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
        else{//reduce time complexity to o(n)
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;

}

void print(Node* head){
    Node *temp=head; 
    //head should not be used directly
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
   
}
int main(){
    //automatic input
    Node* head=takeInput_ef();
    print(head);
    // //static Allocation of node with manual inputs
    // Node n1(1);
    // Node* head=&n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next=&n2;//n2 is static so it has an address
    // n2.next=&n3;
    // n3.next=&n4;
    // n4.next=&n5;
    // print(head);

    //dynamic allocation
    // Node *n3=new Node(3);
    // Node *head=n3;//n3 in dynamic stores location of the node n3

    // Node *n4=new Node(4);
    // n3->next=n4;
}