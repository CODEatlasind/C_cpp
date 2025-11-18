#include <iostream>
using namespace std;
int seq(string input,string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    int smala=seq(input.substr(1),output);
    for(int i=0;i<smala;i++)
    {
        output[i+smala]=input[0]+output[i];   
    }
    return 2*smala;
    
}

int main()
{
    string *n=new string[10];
    int x=seq("abc",n);
    for(int i=0;i<x;i++)
    {
        cout<<n[i]<<endl;
    }
    return 0;
}