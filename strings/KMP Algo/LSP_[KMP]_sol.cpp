/*
KMP uses LSP as a algorithm.

Longest Prefix Suffix

Given a string of characters, find the length of the longest proper prefix which is 
also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the 
function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:		
	int lps(string s) {
	    vector<int>A(s.size(), 0);
	    int j = 0, i = 1;
	    while(i<s.size()){
	        if(s[i]==s[j]){
	            A[i] = j+1;
	            j++;
	            i++;
	        }
	        else{
	            if(j==0)i++;
	            else j = A[j-1];
	        }
	    }
	    return A.back();
	}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        cout<<ob.lps(str)<<endl;
    }
    return 0;
}