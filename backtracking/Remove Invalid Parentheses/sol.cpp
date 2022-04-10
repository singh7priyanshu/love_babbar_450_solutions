/*
Remove Invalid Parentheses

301. Remove Invalid Parentheses

Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make 
the input string valid.

Return all the possible results. You may return the 
answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/

class Solution {
public:
    unordered_set<string> res, vis;
    
    int get_min(string &str){
        int n = str.size();
        stack<char> st;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '(')st.push(str[i]);
            else if(str[i] == ')'){
                if(st.empty()) count++;
                else st.pop();
            }
        }
        count += st.size();
        return count;
    }
    void helper(string str, int min_removal){
        if(vis.find(str) != vis.end())return;
        vis.insert(str);
        if(min_removal == 0){
            res.insert(str);
            return;
        }
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == ')'){
                string left = str.substr(0, i);
                string right = str.substr(i + 1);
                helper(left + right, min_removal - 1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string str) {
        int n = str.size();
        int min_removal = get_min(str);
        helper(str, min_removal);
        vector<string> ans;
        for(auto x : res){
            if(get_min(x) == 0)ans.push_back(x);
        }
        return ans;
    }
};