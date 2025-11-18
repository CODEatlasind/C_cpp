#include <iostream>
#include <stdio.h>
using namespace std;

int fiarr(int a[],int x,int n){
    if (a[n]==x)
    return 1;
    else if (n<0)
    return 0;
    
 
    return fiarr(a,x,n-1);
    
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
    c=fiarr(a,x,k-1);
    if(c==1)
    cout<<"Found";
    else 
    cout<<"Not found";
    return 0;
}