class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class llstack{
    Node* head;
    int size;
    public:
    llstack(){
        head=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    int top(){
        if(isEmpty())
        {
            return 0;
        }
        return head->data;
    }
    void push(int element){
        Node* newnode= new Node(element);
        newnode->next=head;
        head=newnode;
        size++;
    }
    int pop(){
        if(isEmpty())
        {
            return 0;
        }
        int ans=head->data;
        Node* temp=head;
        
        head=head->next;
        size--;
        delete temp;
        return ans;
    }
};