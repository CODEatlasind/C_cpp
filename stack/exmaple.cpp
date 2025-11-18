#include <stack>
#include <string>
int braces(string A) {
    bool ans=false;
    stack<char> s;
    
    for(int i=0;i<A.length();i++){
        if(A[i]=='+' || A[i]=='-'|| A[i]=='*' || A[i]=='/'){
            s.push(A[i]);
            cout<<s.top()
        }
        else if(A[i]=='('){
            s.push(A[i]);
        }
        else if(A[i]==')'){
            if(s.top()=='(')
            ans=true;
            
            while(A[i]=='+' || A[i]=='-'|| A[i]=='*' || A[i]=='/'){
                s.pop();
            }
        }
    }
    if(ans){
        return 1;
    }
    else{
        return 0;
    }
    
}

#include <iostream>
using namespace std;

int main(){
    cout<<braces("((a+b))");
}