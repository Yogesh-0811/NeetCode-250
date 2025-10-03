// 875. Koko Eating Bananas
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canEat(vector<int>& piles,int h,int k){
    long long hours = 0;
    for(int pile:piles){
        hours+=(pile+k-1)/k;
    }
    return hours<=h;
}

int minEatingSpeed(vector<int>&piles,int h){
    int low=1,high=*max_element(piles.begin(),piles.end());
    int ans = high;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(canEat(piles,h,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int num;
    cout<<"Enter number of piles: ";
    cin>>num;

    vector<int>piles(num);
    cout<<"Enter the number of bananas in each pile: ";
    for(int &bananas:piles) cin>>bananas;

    int h;
    cout<<"Enter the hours in which guards will return: ";
    cin>>h;

    int minSpeed = minEatingSpeed(piles,h);
    cout<<"The minimum integer k such that koko can eat all the bananas within h hours: "<<minSpeed<<endl;

    return 0;
}
