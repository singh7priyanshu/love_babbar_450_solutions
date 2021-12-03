/*
Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        int last_match = -1, starj = -1;
        while (i < m){
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                i++; j++;
            }
            else if (j < n && p[j] == '*'){
                starj = j;
                j++;
                last_match = i;
            }
            else if (starj != -1){
                j = starj + 1;
                last_match++;
                i = last_match;
            }
            else return false;
        }
        while (p[j] == '*' && j <n) j++;
        return j == n;
    }
    
};