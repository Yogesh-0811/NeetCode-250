// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int count0=0,count1=0,count2=0;
        // for(int num:nums){
        //     if(num==0) count0++;
        //     else if(num==1) count1++;
        //     else count2++;
        // }
        // int index=0;
        // for(int i=0;i<count0;i++) nums[index++]=0;
        // for(int i=0;i<count1;i++) nums[index++]=1;
        // for(int i=0;i<count2;i++) nums[index++]=2;

        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter the elements in array: ";
    for(int &num:nums) cin>>num;

    Solution obj;
    obj.sortColors(nums);
    cout<<"Array after sorting in place: ";
    for(int num:nums){
        cout<<num<<" ";
    }

    return 0;
}