#include <iostream>
using namespace std;

void swapdat(int a[],int i,int j)
{
    int x=a[i];
    a[i]=a[j];
    a[j]=x;
}

int partition(int a[],int start,int end)
{
    int pivot=start;
    int i=start+1;
    int j=end;
    while(i<j)
    {
        while(a[i]<a[pivot])
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
            swapdat(a,i,j);
    }
    swapdat(a,j,pivot);  
    return j;
}
void quicksort(int a[],int start, int end)
{
    if(start<end)
    {
        int p=partition(a,start,end);
        quicksort(a,start,p-1);
        quicksort(a,p+1,end);
    }
    else
        return;
}
void print(int a[])
{
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<a[9];
}
int main()
{
    int a[]={2,4,3,9,1,4,8,7,5,6};
    cout<<"Intial array:"<<endl;
    print(a);
    quicksort(a,0,9);
    cout<<"Sorted array:"<<endl;
    print(a);
    return 0;
}