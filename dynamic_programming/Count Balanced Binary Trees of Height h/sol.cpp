/*
Count Balanced Binary Trees of Height h

Given a height h, count the maximum number of 
balanced binary trees possible with height h. 
Print the result modulo 109 + 7.

Note : A balanced binary tree is one in which for 
    every node, the difference between heights of left 
    and right subtree is not more than 1.

Example 1:

Input: h = 2
Output: 3 
Explanation: The maximum number of balanced 
binary trees possible with height 2 is 3. 

Example 2:

Input: h = 3
Output: 15
Explanation: The maximum number of balanced
binary trees possible with height 3 is 15. 

Your Task:  
You dont need to read input or print anything. 
Complete the function countBT() which takes h as 
input parameter and returns the maximum number of 
balanced binary trees possible with height h. 

Expected Time Complexity: O(h)
Expected Auxiliary Space: O(h)

Constraints:
1<= n <=103
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int countBT(int h){ 
        long long int dp[h + 1];
        dp[0] = dp[1] = 1; 
        long long int mod = 1000000007;   
        for(int i = 2; i <= h; i++)dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
        return dp[h]; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int h; cin>>h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;
    }
}