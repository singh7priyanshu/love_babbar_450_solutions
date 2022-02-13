/*
Balanced Parenthesis problem.[Imp]

Given an expression string x. Examine whether the pairs and the orders of 
“{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 
'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
Your Task:
This is a function problem. You only need to complete the function ispar() that 
takes a string as a parameter and returns a boolean value true if brackets are 
balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 32000

Note: The drive code prints "balanced" if function return true, otherwise it prints 
"not balanced".

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool ispar(string x){
        stack<char>s;
        for(int i = 0;i<x.size();i++){
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')s.push(x[i]);
            else if(x[i]==']' || x[i]=='}' || x[i]==')'){
                if(s.empty() || !cmp(s.top(), x[i]))return false;
                else s.pop();
            }
        }
        if(s.empty())return true;
        else return false;
    }
    
    bool cmp(char b, char c){
        if(b=='{' && c=='}')return true;
        else if(b=='[' && c==']')return true;
        else if(b=='(' && c==')')return true;
        return false;
    }
};

int main(){
    int t;
    string a;
    cin>>t;
    while(t--){
        cin>>a;
        Solution ob;
        if(ob.ispar(a))cout<<"balanced"<<endl;
        else cout<<"not balanced"<<endl;
    }
}