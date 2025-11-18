#include <iostream>
using namespace std;
string digit(int i)
{
    switch(i)
    {
        case 1:return "";
        case 2:return "abc";
        case 3:return "def";
        case 4:return "ghi";
        case 5:return "jkl";
        case 6:return "mno";
        case 7:return "pqrs";
        case 8:return "tuv";
        case 9:return "wxyz";
    }
}
int seq(int input,string output[])
{
    if(input==0)
    {
        output[0]="";
        return 1;
    }
    int x=seq(input/10,output);
    string y=digit(input%10);
    int z=y.size();
    int d=0;
    //copying elements
    
    for(int j=x;j<z*x;j++)
        {
            if(j%x==0)
            d++;
            output[j]=output[j-d*x];
            
        }
    
    int c=0;
    for(int i=0;i<z*x;i++)
    {
        if(i%x==0 && i!=0)
        c++;
        output[i]+=y[c];
        // c++;
    }
    
    return z*x;
    
}

int main()
{
    string *n=new string[100];

    int z=seq(237,n);
    cout<<z<<endl;
    cout<<"The output array is:"<<endl;
    for(int i=0;i<z;i++)
    {
        cout<<n[i]<<endl;
    }
    return 0;
}