#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//multiplying numbers
 int t=0;

void helper(string s,int start,int end){
     if(start>end)
     return;
     if(s[start]!=s[end])
     t=1;
     helper(s,start+1,end-1);
 }

void pallin(string s){
     int n=s.length();
     if(s[0]!=s[n-1]){
     t=1;
     return;
     }
     helper(s,1,n-2);     
     }
 

 int main(){
    string a;
    cin>>a;
    pallin(a);
    cout<<t;
    return 0;
 }