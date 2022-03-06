/*
Binomial CoefficientProblem

Given two integers n and r, find nCr. Since the answer may 
be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is 
to complete the function nCr() which takes n and r as input 
parameters and returns nCr modulo 109+7..


Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)


Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nCr(int n, int r){
        int mod = 1000000007;
        int c[r+1];
        memset(c, 0, sizeof(c));
        c[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = min(i, r); j>0;j--)c[j]=(c[j]+c[j-1])%mod;
        }
        return c[r]%mod;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}