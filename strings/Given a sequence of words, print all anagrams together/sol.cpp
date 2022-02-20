/*
Given a sequence of words, print all anagrams together

Given an array of strings, return all groups of strings that are anagrams. The groups must 
be created in order of their appearance in the original array. Look at the sample case for 
clarification.

Note: The finial output will be in lexicographic order.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac 
god dog
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
no on
is
Explanation:
There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2. 

Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and 
returns a list of groups such that each group consists of all the strings that are anagrams.


Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.


Constraints:
1<=N<=100

1<=|S|<=10

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> result;
        //hashmap to contains groups of anagrams
        unordered_map<string, vector<string>>umap;
        for(int i = 0;i<string_list.size();i++){
            string s = string_list[i];
            // sort each string
            sort(s.begin(), s.end());
            //add original string to corresponding sorted string in hash map
            umap[s].push_back(string_list[i]);
        }
        for(auto itr = umap.begin();itr != umap.end(); itr++)result.push_back(itr->second);
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string>string_list(n);
        for(int i = 0;i<n;i++)cin>>string_list[i];
        Solution ob;
        vector<vector<string>>result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for(int i = 0;i<result.size();i++){
            for(int j = 0;j<result.size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}