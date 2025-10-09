// Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

// Specifically, ans is the concatenation of two nums arrays.

// Return the array ans.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [1,2,1,1,2,1]
// Explanation: The array ans is formed as follows:
// - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
// - ans = [1,2,1,1,2,1]
// Example 2:

// Input: nums = [1,3,2,1]
// Output: [1,3,2,1,1,3,2,1]
// Explanation: The array ans is formed as follows:
// - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
// - ans = [1,3,2,1,1,3,2,1]
 

#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int>&nums){
    int n=nums.size();
    vector<int>answer(2*n);
    for(int i=0;i<n;i++){
        answer[i]=nums[i];
        answer[i+n]=nums[i];
    }
    return answer;
}

int main(){
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
        
    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int &num:nums) cin>>num;

    vector<int>answer = getConcatenation(nums);
        
    cout<<"The concatenation of two arrays is: ";
    cout<<"[ ";
    for(int ans:answer){
        cout<<ans<<" ";
    }
    cout<<" ]";

    return 0;
}