#include <iostream>
using namespace std;
bool isin(int a){
    if(a==10)
    return true;
    else 
    return false;
}
int main(){
    int a=10;
    cout<<isin(a);
    return 0;
}