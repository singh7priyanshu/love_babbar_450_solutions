/*
Boolean Parenthesization Problem

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression 
so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to 
complete the function countWays() which takes N and S as input 
parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countWays(int N, string S){
        int i, j, len;
        int dpTrue[N][N], dpFalse[N][N];
        for(i = 0;i<N;i+=2){
            if(S[i]== 'T'){
                dpTrue[i][i] = 1;
                dpFalse[i][i] = 0;
            }
            else {
                dpTrue[i][i] = 0;
                dpFalse[i][i] = 1;
            }
        }
        int x = 2;
        while(x<N){
            for(i = 0;(i+x)<N;i+=2){
                dpTrue[i][i+x] = dpFalse[i][i+x] = 0;
                for(j = i+1;j<(i+x);j+=2){
                    if(S[j] == '|'){
                        dpTrue[i][i+x] = (dpTrue[i][i+x] +
                                           dpTrue[i][j-1]*dpTrue[j+1][i+x]+
                                           dpTrue[i][j-1]*dpFalse[j+1][i+x]+
                                           dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
                        dpFalse[i][i+x] = (dpFalse[i][i+x] +
                                           dpFalse[i][j-1]*dpFalse[j+1][i+x])%1003;
                    }else if(S[j] == '&'){
                        dpFalse[i][i+x] = (dpFalse[i][i+x] +
                                           dpFalse[i][j-1]*dpFalse[j+1][i+x]+
                                           dpTrue[i][j-1]*dpFalse[j+1][i+x]+
                                           dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
                        dpTrue[i][i+x] = (dpTrue[i][i+x] +
                                           dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003;
                    }else{
                        dpTrue[i][i+x] = (dpTrue[i][i+x] +
                                           dpFalse[i][j-1]*dpTrue[j+1][i+x]+
                                           dpTrue[i][j-1]*dpFalse[j+1][i+x])%1003;
                        dpFalse[i][i+x] = (dpFalse[i][i+x] +
                                           dpFalse[i][j-1]*dpFalse[j+1][i+x]+
                                           dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003;
                    }
                }
            }
            x += 2;
        }
        return dpTrue[0][N-1]%1003;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        string s; cin>>s;
        Solution ob;
        cout<<ob.countWays(N, s)<<endl;
    }
    return 0;
}

/*
leetcode 

1106. Parsing A Boolean Expression
https://leetcode.com/problems/parsing-a-boolean-expression/

Return the result of evaluating a given boolean expression, 
represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or 
    more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more 
    inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] consists of characters in 
    {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, 
    as given in the description.
*/

class Solution
{
public:
    // function to evaluate expression
    char solve(stack<char> &st)
    {
        bool TrueFlag = false;
        bool FalseFlag = false;
        // keep popping element untill we hit any operator
        while (st.top() != '&' and st.top() != '!' and st.top() != '|')
        {
            if (st.top() == 't')
                TrueFlag = true;
            else
                FalseFlag = true;
            st.pop();
        }
        // take the operator
        char Operator = st.top();
        // pop it from stack
        st.pop();
        // perform and operation
        if (Operator == '&')
        {
            if (!FalseFlag)
                return 't';
        }
        // perform not operation
        else if (Operator == '|')
        {
            if (TrueFlag)
                return 't';
        }
        // perform or operation
        else
        {
            if (FalseFlag)
                return 't';
        }
        return 'f';
    }
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        for (auto x : expression)
        {
            if (x != '(' and x != ')' and x != ',')
            {
                st.push(x);
            }
            if (x == ')')
            {
                // now we have to evaluate the expression
                char exp = solve(st);
                st.push(exp);
            }
        }
        return st.top() == 't' ? true : false;
    }
};