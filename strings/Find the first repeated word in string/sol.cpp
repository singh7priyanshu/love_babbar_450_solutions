/*
Find the first repeated word in string.

Given a sequence of strings, the task is to find out the second most repeated (or frequent) 
string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
secFrequent() which takes the string array arr[] and its size N as inputs and returns the 
second most frequent string in the array.


Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).


Constraints:
1<=N<=103

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string secFrequent (string arr[], int n){
        unordered_map<string, int>m;
        for(int i = 0;i<n;i++)m[arr[i]]++;
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(auto i : m){
            if(i.second>mx1){
                mx2 = mx1;
                mx1 = i.second;
            }
            else if(i.second>mx2 && i.second != mx1)mx2 = i.second;
        }
        for(auto i : m){
            if(i.second == mx2)return i.first;
        }
        return "";
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.secFrequent(arr, n)<<endl;
    }
}