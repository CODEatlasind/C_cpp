#include <iostream>
using namespace std;

int step(int n)
{
 if(n<=0)
 return 0; 

 return((1+step(n-1))+(1+step(n-2))+(1+step(n-3)));
}
int main()
{
    cout<<step(4)<<endl;
}