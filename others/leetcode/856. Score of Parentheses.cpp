/*
856. Score of Parentheses

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ind = 0;
        for(auto i : s){
			if(i == '('){
                st.push(ind);
                ind = 0;
            }
            else {
                ind = st.top() + max(ind*2 ,1);
                st.pop();
            }     
        }
        return ind;
    }
};