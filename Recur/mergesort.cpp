#include <iostream>
using namespace std;

void merge(int a[],int b[])
{
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
    int arr[n1+n2];
    int an[n1], bn[n2];
    for(int i=0;i<n1;i++)
    {
        an[i]=a[i];
    }
    for(int i=0;i<n2;i++)
    {
        bn[i]=a[i];
    }
    int f=0;
    int s=0;
    int i=0;
        while(f<n1 && s<n2)
        {
            if(an[f]<bn[s])
            {
                arr[i]=an[f];
                i++;f++;
            }
            else
            {
                arr[i]=bn[s];
                i++;s++;
            }
        }
         while(s<n2)
            {
                arr[i]=bn[s];
                i++;s++;
            }
        
            while (f<n1)
            {
                arr[i]=an[f];
                i++;f++;
            }
        
    
}

int main()
{
    int arr1[]={6,5,7,3,9};
    int arr2[]={2,4,1};
    merge(arr1,arr2);
    cout<<"merged array:";
    for(int i=0;i<=4;i++)
    {
        cout<<arr[i];
    }
    return 0;
}