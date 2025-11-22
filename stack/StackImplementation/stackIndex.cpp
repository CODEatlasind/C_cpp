#include <bits/stdc++.h>
#include "stackUsingArray.cpp"
using namespace std;

int main()
{
    stackUsingArray stack(5);

    // stack.pop();
    cout << stack.isEmpty() << endl;
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    // stack.push(1);
    cout << stack.top() << endl;
    stack.push(3);
    // stack.push(3);
    cout << stack.size() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << stack.isEmpty() << endl;
    // stack.pop();
}
