/*
Word break Problem[ Very Imp]

Given a string A and a dictionary of n words B, find out if A can be segmented into a 
space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".

Example 2:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream", 
"man", "go", "mango" }
A = "ilikesamsung"
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
 

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter 
and returns 1 if it is possible to break words, else return 0. You don't need to read 
any input or print any output, it is done by driver code.


Expected time complexity: O(s2)

Expected auxiliary space: O(s) , where s = length of string A

 

Constraints:
1 ≤ N ≤ 12
1 ≤ s ≤ 1100 , where s = length of string A
 The length of each word is less than 15.

*/


#include<bits/stdc++.h>
using namespace std;

//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        int i, j, k, n = B.size();
        set<string>mp;
        for(i = 0;i<n;i++)mp.insert(B[i]);
        int len = A.size();
        vector<bool>dp(len+1, false);
        dp[0] = true;
        for(int i = 1;i<=len;i++){
            for(int j = i-1;j>=0;j--){
                if(dp[j] && mp.find(A.substr(j, i-j)) != mp.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string>dict;
        for(int i = 0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<endl;
    }
}