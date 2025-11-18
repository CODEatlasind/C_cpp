#include <iostream>
#include <stdio.h>
using namespace std;
int i=0;
 void fixarr(int a[],int x,int n){
    if (n<0)
    return;
    if(a[n]==x){
    cout<<n+1<<endl;
    
    }
    fixarr(a,x,n-1);
}


int main(){
    int k,x,c=0;
    cout<<"Enter the size of array:"<<endl;
    cin>>k;
    int a[k];
    cout<<"Enter the value of x:"<<endl;
    cin>>x;
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<k;i++){
        cin>>a[i];
     }
     cout<<"ALL instances of the number:"<<endl;
    fixarr(a,x,k-1);
    return 0;
}