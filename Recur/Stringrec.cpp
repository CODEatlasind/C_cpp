#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//replace pi by 3.14 in the string provided
string snew="";
void ripplepi(string a){
    int n=a.length();
    if(a[0]=='\0')
    return ;
    if(a[0]=='p' && a[1]=='i'){
        snew=snew+"3.14";
        ripplepi(a.substr(2,n));
    }
    
    else{
        snew=snew+a[0];
        ripplepi(a.substr(1,n));
    }
}
//remove a given character from a string
void removechar(string a,char ch){
    int n=a.length();
    if(a[0]=='\0')
    return ;
    if(a[0]==ch){
        snew=snew+"";
    }
    
    else{
        snew=snew+a[0];
    }
    removechar(a.substr(1,n),ch);
}
int main(){
    string n;
    char a;
    cout<<"ENTER the string:"<<endl;
    cin>>n;
    cout<<"ENTER the character to be removed:"<<endl;
    cin>>a;
    
    removechar(n,a);
    cout<<"THE OLD string: "<<n<<endl;
    cout<<"THE NEW string: "<<snew<<endl;
    return 0;
}