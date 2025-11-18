#include <stdio.h>
#include <iostream>
using namespace std;
 int c=0;

int main(){
     
     int A[]={20, 8, 22, 4, 12, 10, 14};
     int N=sizeof(A)/sizeof(int);
    for(int i=0;i<N-1;i++)
        {
            int loc=i;
            for(int j=i;j<N;j++)
            {
                if(A[j]<A[loc])
                {
                    int x=A[j];
                    A[j]=A[loc];
                    A[loc]=x;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
          cout<<A[i]<<",";
        }
    return 0;
    }