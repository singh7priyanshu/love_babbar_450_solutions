/*
Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0;
        }
        vector<int>stack={-1};
        int ans =  0;
        for (int i=0;i<s.length();i++){
            if(s[i]=='(') stack.push_back(i);
            else if (stack.size()== 1) stack[0]=i;
            else{
                stack.pop_back();
                ans = max(ans,i-stack.back());
            }
        }
        return ans;
    }
};