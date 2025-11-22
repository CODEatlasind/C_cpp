#include <iostream>

#include "dynstack.cpp"
#include "stackua.cpp"
#include "LLstack.cpp"

using namespace std;

int main(){
    //static stack
    /*stackUsingArr a(4);
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);

    cout<<"SIZE:"<<a.size()<<endl;
    cout<<a.top()<<endl;
    cout<<a.pop()<<endl;

    cout<<a.top()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.isEmpty()<<endl;
    cout<<"SIZE:"<<a.size()<<endl;

    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    
    cout<<a.isEmpty()<<endl;*/

    //Dynamic Stack
    /*stackUsingArrDyn s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(26);

    cout<<"SIZE:"<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<"SIZE:"<<s.size()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.isEmpty()<<endl;*/
    
    //Stack using LL
    llstack s;

    s.push(10);

    cout<<"Is it Empty?"<<s.isEmpty()<<endl;
    s.push(20);
    cout<<"SIZE:"<<s.getsize()<<endl;

    cout<<"Is it Empty?"<<s.isEmpty()<<endl;
    
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<"Is it Empty?"<<s.isEmpty()<<endl;
}
