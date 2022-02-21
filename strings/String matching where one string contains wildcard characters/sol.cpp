/*
String matching where one string contains wildcard characters

Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  
You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

 

Example 1:

Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'. 
Example 2:

Input:
pattern = "a*ab"
str = "baaabab"
Output: 0
Explanation: Because of'a' at first position,
pattern and str can't be matched. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
wildCard() which takes the two strings 'pattern' and 'str' as input parameters and 
returns the answer.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)

Constraints:
1 <= length of(str,pat) <= 200

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int wildCard(string pattern,string str){
        bool isFirst = true;
        int trueVal = pattern.length();
        int dp[str.length()+1][trueVal+1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;
        for(int i =1 ;i<=pattern.length();i++){
            if(pattern[i-1] == '*')dp[0][i] = dp[0][i-1];
        }
        if(trueVal>0 && pattern[0]=='*')dp[0][1] = 1;
        for(int i = 1;i<=str.length();i++){
            for(int j = 1;j<=trueVal;j++){
                if(pattern[j-1] == '?' || pattern[j-1] == str[i-1])dp[i][j] = dp[i-1][j-1];
                else if(pattern[j-1] == '*')dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[str.length()][trueVal];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string pat, text;
        cin>>pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>text;
        Solution ob;
        cout<<ob.wildCard(pat, text)<<endl;
    }
}