#include <bits/stdc++.h>
#include "stackUsingArray.cpp"
#include "stackUsingLinkedList.cpp"
using namespace std;

int main()
{
    // Stack using array
    // stackUsingArray stack(5);
    // stack using linked list
    stackUsingLinkedList stack;

    // stack.pop();
    cout << stack.isEmpty() << endl;
    stack.push(1);
    stack.push(4);
    stack.push(2);
    stack.push(5);
    // stack.push(1);
    cout << stack.top() << endl;
    stack.push(3);
    // stack.push(3);
    cout << stack.getSize() << endl;
    stack.pop();
    stack.pop();

    cout << stack.isEmpty() << endl;
    // stack.pop();
}
