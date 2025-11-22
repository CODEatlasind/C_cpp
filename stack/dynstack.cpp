#include <iostream>
#include <climits>
using namespace std;

class stackUsingArrDyn{
         int *data;
         int nextind;
         int capacity;
    public:
         stackUsingArrDyn(){
            //Default constructor is enabled for this
            data=new int[4];
            //considered constant value is selected
            nextind=0;
            capacity=4;
         }
         //differnce btw static and dynamic stack
         void push(int val){
            if(nextind==capacity){
                //If  condition is met instead of outputing a message we create a new stack and just fill the 1ST in
                capacity*=2;
                int *newdata = new int[capacity];//array of double size is created
                //Data is being copied
                for(int i=0;i<capacity;i++){
                    newdata[i]=data[i];
                }
                //deallocation of old stack 
                delete data;
                //point to new stack
                data=newdata;
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


