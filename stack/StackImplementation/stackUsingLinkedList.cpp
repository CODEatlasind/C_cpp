// #include "../linkedlst/LinkedListImplementation/nodeStructure.h"
#include <stdexcept>
#include <iostream>
using namespace std;

struct nodeStructure
{
    int data;
    nodeStructure *next;

    nodeStructure(int data)
    {
        this->data = data;
        next = nullptr; // null is valid only in c#
    }
};

class stackUsingLinkedList
{
private:
    nodeStructure *head;
    int size;

public:
    stackUsingLinkedList()
    {
        head = nullptr;
        size = 0;
    }
    ~stackUsingLinkedList()
    {
        cout << "\n--- Destructor Started ---" << endl;
        while (head != nullptr)
        {
            /* code */
            nodeStructure *temp = head;
            head = head->next;

            cout << "Deleting node with data: " << temp->data << endl;
            delete temp;
        }
        cout << "--- Destructor Finished ---" << endl;
    }

    void push(int a)
    {
        nodeStructure *temp = new nodeStructure(a);
        temp->next = head;
        head = temp;
        size++;
    }
    int top()
    {
        if (head == nullptr)
            throw out_of_range("STACK UNDERFLOW: Stack is Empty!!");
        return head->data;
    }
    void pop()
    {
        if (head == nullptr)
            throw out_of_range("STACK UNDERFLOW: Stack is Empty!!");

        nodeStructure *temp = head;
        head = head->next;
        size--;
        delete temp;
    }
    int getSize()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
};