//program to find a string in another string using recursion
#include <iostream>
using namespace std;

bool isin(string a,string b){
    if(a.size()<b.size())
        return false;
    if(a.substr(0,b.size())==b)
        return true;
    return isin(a.substr(1),b);//else the string was being chopped off
}

int main(){
    string a,b;
    cin>>a>>b;
    
    cout<<isin(a,b);

    return 0;
}