#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//replace pi by 3.14
int i=0;
string snew="";
void ripplepi(string a){
    if(i==a.length())
    return;
    if(a[i]=='p' && a[i+1]=='i'){
        i+=2;
        snew=snew+"3.14";
    }
    else {
        i++;
        snew=snew+a[i];
    }
    ripplepi(a);
}
int main(){
    string n;
    cin>>n;
    ripplepi(n);
    cout<<snew;
    return 0;
}