// #include "quu.h"
#include "dynqueue.h"

int main(){
    // quu<char> q(5);
    dynqueue<int> q(5);
    cout<<"is EMPTY?\t"<<q.empty()<<endl;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    
    cout<<"SIZE?\t"<<q.getsize()<<endl;

    cout<<q.front()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<"is EMPTY?\t"<<q.empty()<<endl;
    cout<<"SIZE?\t"<<q.getsize()<<endl;
    cout<<q.front()<<endl;
    q.enqueue('f');
    q.enqueue('g');
    
    
    cout<<"is EMPTY?\t"<<q.empty()<<endl;
    cout<<q.front()<<endl;
    q.enqueue('h');
    q.enqueue('i');
    cout<<q.front()<<endl;
    cout<<"SIZE?\t"<<q.getsize()<<endl;
    
}