#include "stackua.cpp"
#include <iostream>
using namespace std;

void insertAtBottom(stackUsingArr &s1,int data){//pop and empty until end then push then data to be added
    if(s1.isEmpty()){
    s1.push(data);
    return;
    }
    int ele=s1.top();
    s1.pop();
    insertAtBottom(s1,data);
    s1.push(ele);
}
void reversest(stackUsingArr &s1){//get the reverse of the stack and then do the adiition to the bottom
    if(s1.isEmpty())
    return ;
    int dat=s1.top();
    s1.pop();
    reversest(s1);
    insertAtBottom(s1,dat);
 }
int main(){
    stackUsingArr s1(6);
    for(int i=0;i<6;i++){
        int dat;
        cin>>dat;
        s1.push(dat);
    }
    // //using different stack(Easy)
    // stackUsingArr s2(6);

    // for(int i=0;i<6;i++){
    //     int dat=s1.top();
    //     s2.push(dat);
    //     s1.pop();
    // }
    // cout<<s1.top();
    
    //Using same stack
    cout<<s1.top();
    reversest(s1);
    cout<<s1.top();
    
    


} 