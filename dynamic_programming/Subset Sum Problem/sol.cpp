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
      int sum =0;
        for(int i=0;i<N;i++)
        sum = sum+arr[i];
       
        return (sum%2==0) && solve(arr, sum/2, N);
        
    }
private:
    int sum = 0;
    
    bool solve(int arr[], int sum, int n){
        bool dp[n+1][sum + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = true; //subset with 0 sum
        
        for(int j=1;j<=sum;j++) dp[0][j] = false; //non-zero sum with 0 elements
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j]; //don't include ith element if it's greater then the rem sum
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               
            }
        }
        
        return dp[n][sum];
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
