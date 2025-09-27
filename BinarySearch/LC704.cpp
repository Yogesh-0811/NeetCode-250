#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int binarySearch(vector<int>& nums, int low,int high, int target){
            if(low>high) return -1;
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) return binarySearch(nums,low,mid-1,target);
            else return binarySearch(nums,mid+1,high,target);
        }

        int search(vector<int>& nums, int target){
            return binarySearch(nums,0,nums.size()-1,target);
        }
};

int main(){
    int n, target;
    cout<< "Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter sorted array elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    cout<<"Enter target element: ";
    cin>>target;

    Solution sol;
    int result = sol.search(nums,target);

    if(result!=-1) cout<<"Target found at index: "<<result<<endl;
    else cout<<"Target not found"<<endl;

    return 0;
}