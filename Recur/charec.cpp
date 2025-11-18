#include <iostream>
using namespace std;

void removechar(char s[],char a,char x){
    if(s[0]=='\0')
    return;
    if(s[0]==a){
        s[0]=x;
    }
    removechar(s+1,a,x);
}

int main(){
    char n[100];
    char a,b;
    cout<<"ENTER the string:";
    cin>>n;
    cout<<"ENTER a:";
    cin>>a;
    cout<<"ENTER x:";
    cin>>b;
    removechar(n,a,b);
    cout<<n;
    return 0;
}