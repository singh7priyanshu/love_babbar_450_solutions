/*
Painting the Fenceproblem

Given a fence with n posts and k colors, find out the 
number of ways of painting the fence so that not more 
than two consecutive fences have the same colors. Since 
the answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6
Explanation: 
We have following possible combinations:

 ___________ _________________________
|_couloured_|_couloured_|_uncouloured_|

 _____________ _________________________
|_uncouloured_|_uncouloured_|_couloured_|

 ___________ _________________________
|_couloured_|_uncouloured_|_couloured_|

 ___________ ___________________________
|_couloured_|_uncouloured_|_uncouloured_|

 ___________ _________________________
|_uncouloured_|_couloured_|_uncouloured_|

 ___________ _________________________
|_uncouloured_|_couloured_|_couloured_|



Example 2:

Input:
N=2,  K=4
Output: 16

Your Task:
Since, this is a function problem. You don't need to take any 
input, as it is already accomplished by the driver code. You 
just need to complete the function countWays() that takes n and k 
as parameters and returns the number of ways in which the fence 
can be painted.(modulo 109 + 7)

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N ≤ 5000
1 ≤ K ≤ 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long countWays(int n, int k){
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = k;
        long long same = 0, diff = k;
        for (int i = 2; i <= n; i++)
        {
            same = diff;
            diff = dp[i-1] * (k-1);
            diff%=1000000007;
            dp[i] = (same + diff);
            dp[i]%=1000000007;
        }
        return dp[n];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countWays(n, k)<<endl;
    }
    return 0;
}
