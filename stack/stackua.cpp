#include <iostream>
#include <climits>
using namespace std;

class stackUsingArr{
         int *data;
         int nextind;
         int capacity;
    public:
         stackUsingArr(int tsize){
            data=new int[tsize];
            nextind=0;
            capacity=tsize;
         }
         void push(int val){
            if(nextind>=capacity){
                cout<<"STACK Full\n";
                return;
             }
            data[nextind]=val;
            nextind++;
        }
        int pop(){
            nextind--;
            if(nextind<0)
            {   
                cout<<"STACK is EMPTY"<<endl;
                return INT_MIN;
            }   
            return data[nextind];
        }
        int top(){
            return data[nextind-1];
        }
        int size(){
            return nextind;
        }
        bool isEmpty(){
            if(nextind==0)
                return true;
            else 
                return false;
        }
};


