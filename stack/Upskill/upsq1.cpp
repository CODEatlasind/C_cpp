#include <bits/stdc++.h>
using namespace std;

string lFactorial(int A) {
    string factorial="";
    vector<int> s;
    s.push_back(1);
    for(int i=2;i<=A;i++){
        int size=s.size(),carry=0,sum=0,j=0;
        
        for( j=0;j<size;j++){
            sum=(s[j]*i)+carry;
            carry=sum/10;
            
            s[j]=sum%10;
            
        
        }
        while(carry!=0){
            s.push_back(carry%10);
            carry/=10;
            
        }
        
    }
    for(int k=s.size()-1;k>=0;k--){
        factorial+=to_string(s[k]);
    }
    
    return factorial;
    
}

int main(){
    cout<<lFactorial(5);
}