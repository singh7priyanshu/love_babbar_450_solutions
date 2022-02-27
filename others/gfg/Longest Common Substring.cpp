/*
Longest Common Substring

Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m){
        int arr[1000][1000], result=0;
        for(int i=0;i<n;i++)arr[i][0]=0;
        for(int j=0;j<m;j++)arr[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(S1[i-1]==S2[j-1])arr[i][j]= 1+arr[i-1][j-1];
                else arr[i][j]=0;
                result=max(result, arr[i][j]);
            }
        }
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        string s1, s2;
        cin>>s1>>s2;
        Solution ob;
        cout<<ob.longestCommonSubstr(s1, s2, n, m)<<endl;
    }
}