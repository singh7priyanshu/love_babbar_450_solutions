/*
Write a program tofind the smallest window that contains all characters of string itself.

Given a string 's'. The task is to find the smallest window length that contains all 
the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function 
findSubString() which takes the string  S as input and returns the length of the smallest 
such window of the string.


Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

 

Constraints:
1 ≤ |S| ≤ 105
String may contain both type of English Alphabets.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const int no_of_chars = 256;
    // Function to find smallest window containing
    // all characters of 'pat'
    string findSubString(string str){
        int len1 = str.length();
        string pat = "";
        
        set<char> s;
        for (int i = 0; i < len1; i++) 
            s.insert(str[i]);
        for (auto i = s.begin(); i != s.end(); i++) 
            pat += (*i);
                
        int len2 = pat.length();
    
        // check if string's length is less than pattern's
        // length. If yes then no such window can exist
        if (len1 < len2) {
            return "";
        }
        int hash_pat[no_of_chars] = {0};
        int hash_str[no_of_chars] = {0};
    
        // store occurrence ofs characters of pattern
        for (int i = 0; i < len2; i++) hash_pat[pat[i]]++;
    
        int start = 0, start_index = -1, min_len = INT_MAX;
    
        // start traversing the string
        int count = 0; // count of characters
        for (int j = 0; j < len1; j++) {
            // count occurrence of characters of string
            hash_str[str[j]]++;
    
            // If string's char matches with pattern's char
            // then increment count
            if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
                count++;
    
            // if all the characters are matched
            if (count == len2) {
                // Try to minimize the window i.e., check if
                // any character is occurring more no. of times
                // than its occurrence in pattern, if yes
                // then remove it from starting and also remove
                // the useless characters.
                while (hash_str[str[start]] > hash_pat[str[start]] ||
                       hash_pat[str[start]] == 0) {
    
                    if (hash_str[str[start]] > hash_pat[str[start]])
                        hash_str[str[start]]--;
                    start++;
                }
                // update window size
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
    
        // If no window found
        if (start_index == -1) {
            return "";
        }
    
        // Return substring starting from start_index
        // and length min_len
        return str.substr(start_index, min_len);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        cout<<ob.findSubString(str).size()<<endl;
    }
    return 0;
}