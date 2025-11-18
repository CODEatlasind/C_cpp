#include <iostream>
#include "demTem.cpp"

using namespace std;

int main(){
    pairs<int, int> n;
    n.setx(5);
    n.sety(2);

    cout<<n.getX()<<endl;
    cout<<n.gety()<<endl;

}