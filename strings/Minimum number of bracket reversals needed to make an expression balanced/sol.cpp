/*
Minimum number of bracket reversals needed to make an expression balanced.

Given a string S consisting of only opening and closing curly brackets '{' and '}', 
find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:

You don't need to read input or print anything. Your task is to complete the function 
countRev() which takes the string S as input parameter and returns the minimum number 
of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 105

*/

#include<bits/stdc++.h>
using namespace std;

int countRev(string s);
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        cout<<countRev(s)<<endl;
    }
}

int countRev (string s){
    if(s.length() & 1)return -1;
    int op = 0, cl = 0;
    int res = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '{')op++;
        else cl++;
        if(cl>op){
            res += cl-op;
            swap(cl, op);
        }
    }
    res += (abs(cl-op))/2;
    return res;
}
