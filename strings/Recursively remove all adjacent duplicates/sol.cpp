/*
Recursively remove all adjacent duplicates

Given a string S delete the characters which are appearing more than once consecutively.

Example 1:

Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:

Input:
S = aabaa
Output:  aba
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.
 

Your Task:
You dont need to read input or print anything. Complete the function 
removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.
 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).
 

Constraints:
1<=|S|<=105
All characters are lowercase alphabets.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removeConsecutiveCharacter(string S){
        //only entering those elements in stack which are unique consecutively..
        stack<char>st;
        for(int i = 0;i<S.length();i++){
            if((st.empty() == 0 && st.top() != S[i]) || st.empty() == 1)st.push(S[i]);
        }
        string res;
        while(st.empty() == 0){
            res += st.top();
            st.pop();
        }
        // reversing the string because stack is a LIFO
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
}
