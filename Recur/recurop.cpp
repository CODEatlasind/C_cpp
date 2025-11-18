#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
//multiplying numbers
int multiply(int m,int n){
    if(n==0)
    return 0;
    return m+multiply(m,n-1);
}
//count till zero
int count(int n){
    if(n==0)
    return 0;
    if(n%10==0)
    return 1+count(n/10);
    else
    return 0+count(n/10);
}
//sum of GP
int i=0;
float sum(int k){
     if(k<0)
     return 0;

     return ((1/pow(2,k))+sum(k-1));
}
//sum of digits
int sumofDigits(int n){
    if(n==0)
    return 0;
    int sum=n%10+sumofDigits(n/10);
    return sum;
}
int main(){
    float s=sumofDigits(9);
    cout<<s;
    return 0;
}