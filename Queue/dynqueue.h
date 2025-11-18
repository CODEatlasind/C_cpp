#include <iostream>
using namespace std;
    
template <typename T>
class dynqueue{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    public:
    dynqueue(int s){
        data=new T[s];
        firstIndex=-1;
        nextIndex=0;
        size=0;
        capacity=s;
    }

    int getsize(){
        return size;
    }

    bool empty(){
        return size==0;
    }
    void enqueue(int a){
        if(size==capacity){
            T *newdata=new T[capacity*2];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newdata[j]=data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newdata[j]=data[i];
                j++;
            }
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
            delete []data;
            data=newdata;
            
            // cout<<"QUEUE Full";
            // return;
        }
        data[nextIndex]=a;
        nextIndex=(nextIndex+1)%capacity;
        size++;

        if(firstIndex==-1)
            firstIndex=0;
    }

    T front(){
        if(empty()){
            cout<<"Queue EMPTY\n";
            return -1;
        }
        return data[firstIndex];
    }
    void dequeue(){
        if(empty()){
            cout<<"Queue EMPTY\n";
            return;
        }
        firstIndex=(firstIndex+1)%capacity;
        size--;
    }
};