#include <iostream>
using namespace std;
void remdup(char a[]){
    if(a[0]=='\0')
    return;
    if(a[0]==a[1]){
        //Shift characters to left
        int i=1;
        for(;a[i]!='\0';i++)
        a[i-1]=a[i];
        a[i-1]=a[i];
        remdup(a);
    }
    else 
    remdup(a+1);
    
}
int main(){
    char s[100];
    cout<<"ENTER the string";
    cin>>s;
    remdup(s);
    cout<<s;
    return 0;
}