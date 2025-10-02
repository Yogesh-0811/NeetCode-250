// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int left = 1,right = x;
        int ans=0;
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(1L*mid*mid<=x){
                ans = mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    int X;
    cout<<"Enter the number: ";
    cin>>X;
    Solution sol;
    int answer = sol.mySqrt(X);
    cout<<"The round down square root of number "<<X<<" is: "<<answer<<endl;
    return 0;
}