/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()){return "";}
        if (strs.size()==1){return strs[0];}
        
        for (int i=0;i<strs[0].size();i++){
            for (int j=0;j<strs.size()-1;j++){
                if (i>=strs[j+1].size() || strs[j][i]!=strs[j+1][i]){
                    return strs[j].substr(0,i);
                }
            }
        }
        
        return strs[0];
    }
};
 
