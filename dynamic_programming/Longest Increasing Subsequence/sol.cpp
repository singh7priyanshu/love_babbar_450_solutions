/*
Longest Increasing Subsequence

Given an array of integers, find the length of the longest 
(strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input 
array and its size as input parameters and returns the length of 
the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int value){
    if(value>arr[h])return h+1;
    while(h>l){
        int middle = (h+l)/2;
        if(arr[middle] == value)return middle;
        if(arr[middle] > value)h = middle;
        else l = middle+1;
    }
    return h;
}

class Solution{
    public:
    int longestSubsequence(int n, int a[]){
       int  lastIndex = 0, tail[n];
       tail[0] = a[0];
       for(int i = 1;i<n;i++){
           int index = binarySearch(tail, 0, lastIndex, a[i]);
           tail[index] = a[i];
           lastIndex = max(lastIndex, index);
       }
       return lastIndex+1;
    }
};

int main(){
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.longestSubsequence(n, a)<<endl;
    }
}