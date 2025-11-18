#include <iostream>
using namespace std;

void sub_seq(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    sub_seq(input.substr(1),output);
    sub_seq(input.substr(1),output+input[0]);
}
int main()
{
    
    sub_seq("abc","");
    return 0;
}