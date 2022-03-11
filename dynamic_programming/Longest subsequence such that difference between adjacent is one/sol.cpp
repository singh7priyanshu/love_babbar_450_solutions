/*
Longest subsequence such that difference between adjacent is one

Given an array A[] of size N, find the longest subsequence 
such that difference between adjacent elements is one.


Example 1:

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.

Example 2:

Input: N = 5
A[] = {1, 2, 3, 4, 5}
Output: 5
Explaination: All the elements can be 
included in the subsequence.

Your Task:
You do not need to read input. Your task is to complete the 
function longestSubseq() which takes N and A[] as input 
parameters and returns the length of the longest such subsequence.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 103


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubsequence(int N, int A[]){
        int dp[N];
        for(int i = 0;i<N;i++)dp[i] = 1;
        for(int i = 1;i<N;i++){
            for(int j = 0;j<i;j++){
                if(abs(A[i]-A[j])==1)dp[i]=max(dp[i], dp[j]+1);
            }
        }
        int ans = 1;
        for(int i = 0;i<N;i++)ans=max(ans, dp[i]);
        return ans;
    }
};


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.longestSubsequence(n, arr)<<endl;
    }
}