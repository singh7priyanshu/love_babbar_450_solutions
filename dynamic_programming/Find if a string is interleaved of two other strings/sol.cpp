/*
Find if a string is interleaved of two other strings

Given strings A, B, and C, find whether C is formed by an 
interleaving of A and B.

An interleaving of two strings S and T is a configuration 
such that it creates a new string Y from the concatenation 
substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, 
XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your 
task is to check whether you can create a string Y which 
can be equal to C.

Specifically, you just need to create substrings of string A 
and create substrings B and concatenate them and check whether 
it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.
Your Task:
Complete the function isInterleave() which takes three 
strings A, B and C as input and returns true if C is an 
interleaving of A and B else returns false. (1 is printed 
by the driver code if the returned value is true, otherwise 0.)

Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B

Constraints:
1 ≤ length of A, B ≤ 100
1 ≤ length of C ≤ 200

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    bool isInterleave(string A, string B, string C) {
        int m=A.size();
        int n=B.size();
        if(m==0 && n==0 && C.size()==0)return true;
        if(m+n !=C.size())return false;
        if(m==0 && n==0)return false;
        vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(A[i-1]==C[i-1] && dp[i-1][0]==true)dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            if(B[i-1]==C[i-1] && dp[0][i-1]==true)dp[0][i]=true;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int k=i+j-1;
                if(A[i-1]==C[k] && dp[i-1][j]==true) dp[i][j]=true;
                if(B[j-1]==C[k] && dp[i][j-1]==true)dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string a, b, c;
        cin>>a>>b>>c;
        Solution ob;
        cout<<ob.isInterleave(a, b, c)<<endl;
    }
    return 0;
}