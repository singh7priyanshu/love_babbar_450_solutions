/*
Count All Palindromic Subsequence in a given String.

Given a string str of length N, you have to find number of palindromic subsequence 
(need not necessarily be distinct) which could be formed from the string str.
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
You don't need to read input or print anything. Your task is to complete the function 
countPs() which takes a string str as input parameter and returns the number of 
palindromic subsequence.
 

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
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}