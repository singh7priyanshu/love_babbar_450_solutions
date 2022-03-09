/*
Subset Sum Problem

Given an array arr[] of size N, check if it can be partitioned 
into two parts such that the sum of elements in both parts is 
the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to 
complete the function equalPartition() which takes the value N and 
the array as input parameters and returns 1 if the partition is 
possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i = 0;i<N;i++)sum+=arr[i];
        vector<vector<int>>dp(N, vector<int>(sum+1, -1));
        int x = cal(0, arr, 0, sum, N, dp);
        return x;
    }
    
    int cal(int node, int a[], int cur, int sum, int n, vector<vector<int>>&dp){
        if(node>=n){
            if(cur*2 != sum)return 0;
            else return 1;
        }
        if(cur*2>sum)return dp[node][cur] = 0;
        if(cur*2 == sum)return dp[node][cur] = 1;
        if(dp[node][cur] != -1)return dp[node][cur];
        int f = 0;
        f = cal(node+1, a, cur+a[node], sum, n, dp) | cal(node+1, a, cur, sum, n, dp);
        return dp[node][cur] = f;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        if(ob.equalPartition(n, arr))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}