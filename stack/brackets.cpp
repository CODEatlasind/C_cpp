//Program to find minimum move to close all brackets
#include <iostream>
#include <stack>
using namespace std;

int  minibrack(string A){
    stack<char> s;

    for(auto &ch:A){
        if(ch=='{')
            s.push(ch);
        else if(ch=='}' && !s.empty())
            s.pop();
    }

    if(s.size()%2==0)   //if even means brackets can be closed
        return (s.size()/2);
    else    //odd mean bracket pair cant be created
        return -1;
}

int main(){
    string A="{{{{}}";
    cout<<minibrack(A);
}