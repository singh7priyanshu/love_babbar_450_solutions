/*
Maximum profit by buying and selling a share at most k times

In the stock market, a person buys a stock and sells it 
on some future date. Given the stock prices of N days in 
an array A[ ] and a positive integer K, find out the maximum 
profit a person can make in at-most K transactions. 

A transaction is equivalent to (buying + selling) of a 
stock and new transaction can start only when the previous 
transaction has been completed.


Example 1:

Input: K = 2, N = 6
A = {10, 22, 5, 75, 65, 80}
Output: 87
Explaination: 
1st transaction: buy at 10 and sell at 22. 
2nd transaction : buy at 5 and sell at 80.
Example 2:

Input: K = 3, N = 4
A = {20, 580, 420, 900}
Output: 1040
Explaination: The trader can make at most 2 
transactions and giving him a profit of 1040.
Example 3:

Input: K = 1, N = 5
A = {100, 90, 80, 50, 25}
Output: 0
Explaination: Selling price is decreasing 
daily. So seller cannot have profit.

Your Task:
You do not need to read input or print anything. 
Your task is to complete the function maxProfit() 
which takes the values K, N and the array A[] as input 
parameters and returns the maximum profit.


Expected Time Complexity: O(N*K)
Expected Auxiliary Space: O(N*K)


Constraints:
1 ≤ N ≤ 500
1 ≤ K ≤ 200
1 ≤ A[ i ] ≤ 1000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        if(N == 0) return 0;
        int n = K * 2 + 1;
        vector<int> dp(n, 0);
        for (int i = 0; i < K; i++) {
            dp[1 + i * 2] = -A[0];
        }
        for (int i = 1; i < N; i++) {
            dp[0] = dp[0];
            for (int j = 0; j < K; j++) {
                dp[1 + j * 2] = max(dp[1 + j * 2], dp[j * 2] - A[i]);
                dp[2 + j * 2] = max(dp[2 + j * 2], dp[1 + j * 2] + A[i]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < K; i++) ans = max(ans, dp[2 + i * 2]);
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N, K;
        cin>>K>>N;
        int A[N];
        for(int i = 0;i<N;i++)cin>>A[i];
        Solution ob;
        cout<<ob.maxProfit(K, N, A)<<endl;
    }
    return 0;
}