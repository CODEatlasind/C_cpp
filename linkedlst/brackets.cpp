#include <stack>
#include <iostream>
using namespace std;

int main(){
    stack<char> s;
    string sent;
    cout<<"ENTER a string of brackets:";
    cin>>sent;

    for (int i = 0; i < sent.size(); i++)
    {
        if(sent.at(i)=='{' || sent.at(i)=='[' || sent.at(i)=='('){
            s.push(sent.at(i));
        }
    }
    for(int j=0;j < sent.size();j++){
        if(sent.at(j)=='}' && s.top()=='{')
            s.pop();
        else if(sent.at(j)==')' && s.top()=='(')
            s.pop();
        else if(sent.at(j)==']' && s.top()=='[')
            s.pop();
    }
    if(s.empty())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}