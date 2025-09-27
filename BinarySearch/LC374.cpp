#include <iostream>
using namespace std;

int pickednumber;

int guess(int num){
    if(num==pickednumber) return 0;
    else if(num>pickednumber) return -1;
    else return 1;
}

class Solution {
    public:
        // int guessNumber(int n){
        //     int low=1,high=n;
        //     while(low<=high){
        //         int mid = low + (high-low)/2;
        //         int result = guess(mid);
        //         if(result==0) return mid;
        //         else if(result == -1) high=mid-1;
        //         else low = mid+1;
        //     }
        //     return -1;
        // }

        //Recursive solution
        int solve(int low,int high){
            if(low>high) return -1;
            int mid = low+(high-low)/2;
            int res = guess(mid);

            if(res==0) return mid;
            else if(res==-1) return solve(low,mid-1);
            else return solve(mid+1,high);
        }
        int guessNumber(int n){
            return solve(1,n);
        }
};

int main(){
    int n;
    cout<<"Enter the upper bound n: ";
    cin>>n;
    cout<<"Enter the picked number (hidden in leetcode soln): ";
    cin>>pickednumber;

    Solution sol;
    int ans = sol.guessNumber(n);
    cout<<"The picked number is: "<<ans<<endl;

    return 0;
}