// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:

    bool canSplit(vector<int>&nums,int k, int mid){
        int count=1;
        long long currSum=0;
        for(int num:nums){
            if(currSum+num>mid){
                count++;
                currSum=num;
                if(count>k)return false;
            }else{
                currSum+=num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canSplit(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter the number of elements in vector: ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int &num:nums) cin>>num;

    int k;
    cout<<"Enter the number of splits allowed: ";
    cin>>k;

    Solution sol;

    int answer = sol.splitArray(nums,k);
    cout<<"The minimized largest sum of the split is: "<<answer<<endl;

    return 0;
}