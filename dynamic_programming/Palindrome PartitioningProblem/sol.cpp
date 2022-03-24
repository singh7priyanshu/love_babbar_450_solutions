/*
Palindrome PartitioningProblem

Given a string str, a partitioning of the string is a palindrome 
partitioning if every sub-string of the partition is a palindrome. 
Determine the fewest cuts needed for palindrome partitioning 
of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, 
Your task is to complete the function palindromicPartition() 
which takes the string str as input parameter and returns 
minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        int c[n], i, j, k, l;
        bool p[n][n];
        for(i = 0;i<n;i++)p[i][i] = true;
        for(l = 2;l<=n;l++){
            for(i = 0;i<n-l+1;i++){
                j = i+l-1;
                if(l == 2)p[i][j] = (str[i] == str[j]);
                else p[i][j] = ((str[i] == str[j]) & p[i+1][j-1]);
            }
        }
        for(i = 0;i<n;i++){
            if(p[0][i])c[i] = 0;
            else {
                c[i] = INT_MAX;
                for(j = 0;j<i;j++){
                    if(p[j+1][i] == true & c[j]+1<c[i])c[i] = c[j]+1;
                }
            }
        }
        return c[n-1];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        cout<<ob.palindromicPartition(str)<<endl;
    }
    return 0;
}


/*

leetcode 

131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring 
of the partition is a palindrome. Return all possible 
palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition(s, 0, path, result);//dfs calls
        return result;
    }
private: 
    //DFS steps
    void partition(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        int n = s.length();
        if (start == n) {
            result.push_back(path);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, path, result);
                    path.pop_back();
                }
            }
        }
    }
    //helper function to safe check whether a substr is palindrome or not
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};