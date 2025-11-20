#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// If default array is being considered then its size is fixed and can't be resized
class stackUsingArray
{
public:
    stackUsingArray(int n)
    {
        this->n = n;
        arr = new int[n];
        idx = -1;
    }

    ~stackUsingArray()
    {
        delete[] arr;
    }

    void push(int a)
    {
        if (idx == n - 1)
        {
            throw out_of_range("Stack overflow: Array out of bounds");
        }
        // if (idx < n - 1)
        arr[++idx] = a;
        // Will the stack overflow trigger?
        // else
        //     throw out
    }
    void pop()
    {
        if (idx < 0)
        {
            throw out_of_range("Stack underflow: Stack is empty");
        }
        arr[idx--] = 0;
    }
    int top()
    {
        if (idx < 0)
        {
            throw invalid_argument("Stack is empty");
        }

        return arr[idx];
    }
    int size()
    {
        return idx >= 0 ? idx + 1 : 0;
    }
    bool isEmpty()
    {
        return idx == -1;
    }

private:
    int *arr;
    int n;
    int idx;
};