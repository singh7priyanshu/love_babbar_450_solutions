/*
Longest Palindromic Subsequence

Given a sequence, find the length of the longest 
palindromic subsequence in it.
 
INPUT : GEEKSFORGEEKS
OUTPUT : 5

The longest palindromic subsequence we can get is of 
length 5. There are more than palindromic subsequences
of length 5, for example, EEKEE, EESEE, EEFEE, ..


As another example, if the given sequence is “BBABCBCAB”, 
then the output should be 7 as “BABCBAB” is the longest 
palindromic subsequence in it. 

“BBBBB” and “BBCBB” are also palindromic subsequences 
of the given sequence, but not the longest ones.

The naive solution for this problem is to generate all 
subsequences of the given sequence and find the longest 
palindromic subsequence. 

This solution is exponential in terms of time complexity.

Let us see how this problem possesses both 
important properties of a Dynamic Programming (DP) Problem 
and can efficiently be solved using Dynamic Programming.
1) Optimal Substructure: 
Let X[0..n-1] be the input sequence of length n and 
    L(0, n-1) be the length of the longest palindromic 
    subsequence of X[0..n-1]. 
If last and first characters of X are same, 
    then L(0, n-1) = L(1, n-2) + 2. 
Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)). 
 

Following is a general recursive solution with 
all cases handled. 
 

// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 
2) Overlapping Subproblems 
Following is a simple recursive implementation of the 
LPS problem. The implementation simply follows the 
recursive structure mentioned above. 
 

*/
// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;
 
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
    return 1;
 
// Base Case 2: If there are only 2
// characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
    return 2;
 
// If the first and last characters match
if (seq[i] == seq[j])
    return lps (seq, i+1, j-1) + 2;
 
// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    cout << "The length of the LPS is "
         << lps(seq, 0, n-1);
    return 0;
}
 
/*
Output
The length of the LPS is 5
Considering the above implementation, the following is a 
partial recursion tree for a sequence of length 6 with all 
different characters. 
 

               L(0, 5)
             /        \ 
            /          \  
        L(1,5)          L(0,4)
       /    \            /    \
      /      \          /      \
  L(2,5)    L(1,4)  L(1,4)  L(0,3)
In the above partial recursion tree, L(1, 4) is being 
solved twice. If we draw the complete recursion tree, 
then we can see that there are many subproblems that are 
solved again and again. Since the same subproblems are 
called again, this problem has the Overlapping Subproblems 
property. So LPS problem has both properties 
(see this and this) of a dynamic programming problem. 

Like other typical Dynamic Programming(DP) problems, 
recomputations of the same subproblems can be avoided 
by constructing a temporary array L[][] in a bottom-up
manner.
Dynamic Programming Solution 
 

*/
// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence in seq
#include<stdio.h>
#include<string.h>
 
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
 
 
   // Strings of length 1 are palindrome of length 1
   for (i = 0; i < n; i++)
      L[i][i] = 1;
 
    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
    // substring
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][n-1];
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The length of the LPS is %d", lps(seq));
    getchar();
    return 0;
}
/*
Output
The length of the LPS is 7
The Time Complexity of the above implementation 
is O(n^2) which is much better than the worst-case time 
complexity of Naive Recursive implementation.

Using Memoization Technique of Dynamic programming
The idea used here is to reverse the given input string 
and check the length of the longest common subsequence. 
That would be the answer for the longest palindromic 
subsequence.

*/
// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence
// in seq
#include <bits/stdc++.h>
using namespace std;
 
int dp[1001][1001];
 
// Returns the length of the longest palindromic subsequence
// in seq
int lps(string& s1, string& s2, int n1, int n2)
{
    if (n1 == 0 || n2 == 0) {
        return 0;
    }
    if (dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
    if (s1[n1 - 1] == s2[n2 - 1]) {
        return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
    }
    else {
        return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2),
                                lps(s1, s2, n1, n2 - 1));
    }
}
 
/* Driver program to test above functions */
int main()
{
    string seq = "GEEKS FOR GEEKS";
    int n = seq.size();
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    string s2 = seq;
    reverse(s2.begin(), s2.end());
    cout << "The length of the LPS is "
         << lps(s2, seq, n, n) << endl;
    return 0;
}
/*
Output
The length of the LPS is 7
Time Complexity: O(n*n)
*/

/*
same question on leetcode;

516. Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic 
subsequence's length in s.

A subsequence is a sequence that can be derived from 
another sequence by deleting some or no elements 
without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        char seq[n+1];
        strcpy(seq, s.c_str());
        int sol = lps(seq);
        return sol;
    }
    int lps(char *str){
        int n = strlen(str);
        int i, j, cl;
        int L[n][n];
        for (i = 0; i < n; i++)L[i][i] = 1;
        for (cl=2; cl<=n; cl++){
        for (i=0; i<n-cl+1; i++){
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
            }
        }
        return L[0][n-1];
    }
    int max (int x, int y) { return (x > y)? x : y; }
};
