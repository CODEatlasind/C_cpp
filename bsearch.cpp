#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size();
         int mid=0;
        while(start<end){
            mid=(start+end)/2;
            
        if(nums[mid]==target)
            return mid;
            
        
        else if(nums[mid]>target)
            end=mid;
            
        else 
            start=mid;
            
        }
        return mid+1;
        
    }
    int main{
        vector<int> arr;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        ci
        searchInsert(arr,)
        return 0;
    }