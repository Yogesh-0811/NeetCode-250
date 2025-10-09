// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true
// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation:
// All elements are distinct.

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>&nums){
    unordered_set<int>seen;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(seen.find(nums[i])==seen.end()){
            seen.insert(nums[i]);
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter the elements: ";
    for(int &num:nums) cin>>num;

    if(containsDuplicate(nums)){
        cout<<"Given array contains duplicate elements.";
    }else{
        cout<<"Given array does not contain any duplicate elements.";
    }

    return 0;
}