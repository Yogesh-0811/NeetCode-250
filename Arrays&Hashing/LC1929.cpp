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