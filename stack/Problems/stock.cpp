//stock span
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> stockSpan(vector<int> arr){
    stack<int> s;
    vector<int> span;
    s.push(0);
    span.push_back(1);
    for(int i=1;i<arr.size();i++){
        while(!s.empty() && arr[i]>arr[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            span.push_back(i-s.top());
        }
        else {
            span.push_back(i+1);
        }
        s.push(i);
    }
    return span;
}


int main(){
    vector<int> arr={100, 80, 60, 70, 60, 75, 85};
    
    vector<int> b=stockSpan(arr);
    for(int i=0;i<arr.size();i++){
        cout<<b[i]<<endl;
    }
    
}