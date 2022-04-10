/*
Word Break Problem using Backtracking

Given a string s and a dictionary of words dict of 
length n, add spaces in s to construct a sentence 
where each word is a valid dictionary word. 

Each dictionary word can be used more than once. 
Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.


Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking 
of the string s where all the words are present 
in dict.
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function wordBreak() 
which takes n, dict and s as input parameters and 
returns a list of possible sentences. 

If no sentence is possible it returns an empty list.

Expected Time Complexity: O(N2*n) where N = |s|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ n ≤ 20
1 ≤ dict[i] ≤ 15
1 ≤ |s| ≤ 500 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    unordered_map<string, vector<string>> m;
    
    void combine(vector<string> &v, string w){
        for(int i = 0;i < v.size();i++){
            v[i] += " "+w;
        }
    }
    
    vector<string> cal(string s, unordered_set<string> &mp){
        if(m.find(s) != m.end()) 
            return m[s];
        vector<string> result;
        if(mp.find(s) != mp.end()) 
            result.push_back(s);
        for(int i = 1;i < s.size();i++){
            string rem = s.substr(i);
            if(mp.find(rem) != mp.end()){
                vector<string> v = cal(s.substr(0,i), mp);
                combine(v, rem);
                result.insert(result.end(), v.begin(), v.end());
            }
        }
        m[s] = result;
        return result;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s) 
    {
        unordered_set<string> mp;
        for(int i = 0;i < n;i++)
            mp.insert(dict[i]);
        vector<string> ans = cal(s, mp);
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        vector<string>dict;
        string s;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        Solution ob;
        vector<string>ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)cout<<"Empty"<<endl;
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i<ans.size();i++)cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}