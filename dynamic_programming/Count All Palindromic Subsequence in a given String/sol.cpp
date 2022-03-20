/*
Count All Palindromic Subsequence in a given String

Now this question may have two types.
    1. count the all the palindromic subsequence(geeksforgeeks one)
    2. count all the unique subsequence(leetcode one)

GFG

Given a string str of length N, you have to find number 
of palindromic subsequence (need not necessarily be distinct) 
which could be formed from the string str.
Note: You have to return the answer module 109+7;
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 

Example 2:

Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
 

Your Task:
You don't need to read input or print anything. Your task is to 
complete the function countPs() which takes a string str as input 
parameter and returns the number of palindromic subsequence.
 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1<=length of string str <=1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const long long int mod = 1000000007;
    long long int  countPS(string str){
        long long int N = str.length();
        long long int cps[N+1][N+1];
        memset(cps, 0, sizeof(cps));
        for(long long int i = 0;i<N;i++)cps[i][i] = 1;
        for(long long int L = 2;L<=N;L++){
            for(long long int i = 0;i<=N-L;i++){
                long long int k = L+i-1;
                if(str[i]==str[k])cps[i][k] = add(cps[i][k-1], add(cps[i+1][k], 1LL))%mod;
                else cps[i][k] = add(cps[i][k-1], sub(cps[i+1][k], cps[i+1][k-1]))%mod;
           }
       }
       return cps[0][N-1]%mod;
    }
    long long int add(long long int x, long long int y){
        return ((x%mod)+(y%mod))%mod;
    }
    long long int sub(long long int x, long long int y){
        return ((x%mod)-(y%mod)+mod)%mod;
    }
     
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}

/*
Leetcode 

Given a string s, return the number of different 
non-empty palindromic subsequences in s. Since the 
answer may be very large, return it modulo 109 + 7.

A subsequence of a string is obtained by deleting zero 
or more characters from the string.

A sequence is palindromic if it is equal to the 
sequence reversed.

Two sequences a1, a2, ... and b1, b2, ... are different 
if there is some i for which ai != bi.

 

Example 1:

Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic 
subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it 
occurs twice.
Example 2:

Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty 
palindromic subsequences, which is 104860361 modulo 109 + 7.
 

Constraints:

1 <= s.length <= 1000
s[i] is either 'a', 'b', 'c', or 'd'.


*/

class Solution {
public:
    int countPalindromicSubsequences(string str) {
        int n = str.size() ; 
        long long mod = 1000000007 ; 
        vector<int>next(n) , prev(n) ; 
        map<char,int>m ; 
        for(int i = 0 ; i<n ; i++){
            char ch = str[i] ; 
            if(m[ch]){
                prev[i] = m[ch] - 1 ; 
                m[ch] = i + 1 ; 
            }
            else{
                m[ch] = i+1 ; 
                prev[i] = -1 ; 
            }
        }
        m.clear() ; 
        for(int i = n-1 ; i>=0 ; i--){
            char ch = str[i] ; 
            if(m[ch]){
                next[i] = m[ch] - 1 ; 
                m[ch] = i + 1 ; 
            }
            else{
                m[ch] = i + 1 ; 
                next[i] = -1 ; 
            }
        }

        vector<vector<long long>>dp(n , vector<long long>(n , 0)) ; 
        int i = 0 ; 
        int j = 0 ; 
        int lastcol = 0 ;
        while(1){
            while(i < n && j < n){
                int gap = j - i ; 
                if(gap == 0) dp[i][j] = 1 % mod ; 
                else if(gap == 1) dp[i][j] = 2 % mod ; 
                else {
                    if(str[i] != str[j]) dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % mod ; 
                    else
                    {
                        if(next[i] == j && prev[j] == i) dp[i][j] = (2 * dp[i+1][j-1] + 2) % mod ;
                        else if(next[i] == prev[j]) dp[i][j] = (2 * dp[i+1][j-1] + 1) % mod ; 
                        else dp[i][j] = (2 * dp[i+1][j-1] - dp[next[i] + 1][prev[j] - 1]) % mod ;   
                    }
                }
                i++ ; 
                j++ ; 
            }
            if(lastcol == n-1) break ; 
            i = 0 ; 
            j = lastcol + 1 ; 
            lastcol = j ; 
        }
        if(dp[0][n-1] < 0) dp[0][n-1] += mod ; 
        return dp[0][n-1] ;
    }
};