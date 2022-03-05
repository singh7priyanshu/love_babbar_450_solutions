/*
392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, 
or false otherwise.

A subsequence of a string is a new string that is formed from the 
original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/

class Solution {
public:
    bool solve(string &s, string &t, int n1, int n2)
    {
        if(n1 == 0)return true;
        if(n2 == 0)return false;
        if(s[n1 - 1] == t[n2 - 1])return solve(s, t, n1 - 1, n2 - 1);
        return solve(s, t, n1, n2 - 1);
    }
    bool isSubsequence(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
       return solve(s, t, n1, n2);
    }
};