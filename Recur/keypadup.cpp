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
void seq(int input,string output)
{
    if(input==0)
    {
        cout<<output<<endl;
        return;
    }
    // seq(input/10,output);
    string z=digit(input%10);
    seq(input/10,z[0]+output);
    seq(input/10,z[1]+output);
    seq(input/10,z[2]+output);

    
}

int main()
{
    seq(27,"");
    return 0;
}