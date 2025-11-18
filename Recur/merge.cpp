#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int an[n1];
    int bn[n2];
    for(int i=0;i<n1;i++)
    {
        an[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        bn[i]=a[m+1+i];
    }
    int f=0;
    int s=0;
    int i=l;
        while(f<n1 && s<n2)
        {
            if(an[f]<bn[s])
            {
                a[i]=an[f];
                i++;f++;
            }
            else
            {
                a[i]=bn[s];
                i++;s++;
            }
        }
         while(s<n2)
            {
                a[i]=bn[s];
                i++;s++;
            }
        
            while (f<n1)
            {
                a[i]=an[f];
                i++;f++;
            }
        
    
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int arr[]={-4,-2,-2,3};
    mergesort(arr,0,3);
    cout<<"Sorted array:";
    for(int i=0;i<4;i++)
    {
        cout<<arr[i];
    }
    return 0;
}