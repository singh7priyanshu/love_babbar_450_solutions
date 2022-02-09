/*
Write a program to find the longest Palindrome in a string.[ Longest palindromic Substring]

Given a string S, find the longest palindromic substring in S. Substring of 
string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome 
if reverse(S) = S. Incase of conflict, return the substring which occurs first 
( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalin (string S) {
        int i = 0, l, h = 0;
        for(int i = 0;i<S.size();i++){
            int length1 = helper(S, i, i);
            int length2 = helper(S, i, i+1);
            int length = max(length1, length2);
            if(h-l < length-1){
                l = i-(length-1)/2;
                h = i+(length)/2;
            }
        }
        return S.substr(l, h-l+1);
    }
    
    int helper(string s, int l, int h){
        while(l>=0 && h<s.size() && s[l]==s[h]){
            l--;
            h++;
        }
        return h-l-1;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string S; cin>>S;
        Solution ob;
        cout<<ob.longestPalin(S)<<endl;
    }
}

/*
another leetcode question 5. Longest Palindromic Substring using DP

Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"
Example 3:
Input: s = "a"
Output: "a"
Example 4:
Input: s = "ac"
Output: "a"


        class Solution {
        public:
                string longestPalindrome(string s) {
                        int n = s.size();        
                        if(n<=1)
                                return s;

                        // table[i][j] represents whether string i to j is a palindrome or NOT
                        bool table[n][n];
                        memset(table,false,sizeof(table));
        
        
                        // Base condition => Single letter is always a palindrome
        
                        for(int i=0;i<n;i++)
                                table[i][i]=true;            
        
        
                        // ex. str => Asome_palindromeA
                        //              i................j
                        //  if str[i]==str[j] and string i+1 to j-1 is
                        //    pallindrome then str i to j is palindrome  
        
                        // if len of str is 2 then
                        // str[i+1]==[i] is condition for str to be pall...
                        // Example  str=> C.C 
                        //                i.i+1
        
        
                        int start =0;
                        int maxLen=1;
        
                        for(int i=0;i<n;i++){
                                if(s[i]==s[i+1]){
                                        start=i;
                                        maxLen=2;
                                        table[i][i+1]=true;
                                }
                        }
        
                        for(int k=3;k<=n;k++){
                                for(int i=0;i<n-k+1;i++){
                                        int j=i+k-1;
                                        if(s[i]==s[j] && table[i+1][j-1]==true){
                                                table[i][j]=true;
                                                start=i;
                                                if(maxLen<j-i+1)
                                                        maxLen=j-i+1;
                                        }
                                }
                        }
               
                        return s.substr(start,maxLen);
        
                }
        };



*/