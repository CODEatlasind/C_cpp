#include <iostream>
using namespace std;

int c=0;
void toi(int n,char source,char auxillary,char destin){
if(n==1){
cout<<source<<"->"<<destin<<endl;
return;
}

toi(n-1,source,destin,auxillary);
cout<<source<<"->"<<destin<<endl;
toi(n-1,auxillary,source,destin);
}
int main(){
    int n;
    cout<<"Enter thr number of DSKS: \n";
    cin>>n;
    toi(n,'a','b','c');
    
    return 0;
}