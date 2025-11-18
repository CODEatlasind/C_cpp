#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int soi(string s,int a){
    if(a<0)
    return 0;
    if(s[a]>=48 && s[a]<=57)
    return(10*soi(s,a-1)+(s[a]-48));
    //else 
   // return(soi(s.substr(1,n)));
    
}
int main(){
    string n;
    cout<<"ENTER the string:"<<endl;
    cin>>n;
    int a=n.length()-1;
    int c=soi(n,a);
    cout<<c;
    
    return 0;
}