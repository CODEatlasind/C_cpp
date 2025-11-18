#include <iostream>
#include <string>
using namespace std;
string snew="";
void pstar(string a,int i){
    if(i==a.length())
    return;
    if(a[i]==a[i+1])
    snew =snew+a[i]+"*";
    else 
    snew=snew+a[i];
    pstar(a,i+1);
    }
int main(){
    string n;
    cout<<"ENTER the string:"<<endl;
    cin>>n;
    pstar(n,0);
    cout<<snew;
    
    return 0;
}