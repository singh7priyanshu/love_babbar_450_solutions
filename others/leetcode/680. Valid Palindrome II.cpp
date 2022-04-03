/*
680. Valid Palindrome II

Given a string s, return true if the s can be 
palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int st = 0;
        int lt = s.size()-1;
        int count = 0;
        
        while(st<=lt){
            if(s[st]==s[lt]){
                st++;
                lt--;
            }
            else {
                st++;
                count++;
            }
        }
    int count1 = 0;
        st=0;
        lt = s.size()-1;
        while(st<=lt){
            if(s[st]==s[lt]){
                st++;
                lt--;
            }
            else {
                lt--;
                count1++;
            }
        }
        if(count1<=1||count<=1){
            return true;
        }
        else return false;  
    }
};