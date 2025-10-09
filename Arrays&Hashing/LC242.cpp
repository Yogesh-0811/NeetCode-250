// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s1,string s2){
    unordered_map<char,int>freqCount;
    for(char ch:s1){
        freqCount[ch]++;
    }
    for(char ch:s2){
        freqCount[ch]--;
    }
    for(auto it:freqCount){
        if(it.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1;
    cout<<"Enter first string s1: ";
    cin>>s1;

    string s2;
    cout<<"Enter second string s2: ";
    cin>>s2;

    if(isAnagram(s1,s2)){
        cout<<"Second String s2 is an anagram of first string s1.";
    }

    return 0;
}
 