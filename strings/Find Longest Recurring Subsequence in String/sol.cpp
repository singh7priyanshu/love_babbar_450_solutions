/*
Find Longest Recurring Subsequence in String

Given a string str, find the length of the longest repeating subsequence such that it 
can be found twice in the given string. The two identified subsequences A and B can use 
the same ith character from string str if and only if that ith character has different 
indices in A and B.

Example 1:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "aab"
Output: 1
Explanation: 
The longest reapting subsequenece is "a".

Your Task:
You don't need to read or print anything. Your task is to complete the 
LongestRepeatingSubsequence() which takes str as input parameter and returns 
the length of the longest repeating subsequnece.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)


Constraints:
1 <= |str| <= 103

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    int dp[n+1][n+1];
		    for(int i = 0;i<=n;i++){
		        for(int j = 0;j<=n;j++)dp[i][j] = 0;
		    }
		    for(int i = 1;i<=n;i++){
		        for(int j = 1;j<=n;j++){
		            if(str[i-1] == str[j-1] && i!=j)dp[i][j] = 1 + dp[i-1][j-1];
		            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		        }
		    }
		    return dp[n][n];
		}

};

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        Solution ob;
        int ans = ob.LongestRepeatingSubsequence(str);
        cout<<ans<<endl;
    }
    return 0;
}