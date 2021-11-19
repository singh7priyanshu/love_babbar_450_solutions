"""
Coin ChangeProblem

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.


Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n).


Constraints:
1 <= n,m <= 103
"""


class Solution:
    def count(self, S, m, n): 
        # code here
        # We need n+1 rows as the table is constructed 
        # in bottom up manner using the base case 0 value
        # case (n = 0)
        table = [[0 for x in range(m)] for x in range(n+1)]
    
        # Fill the entries for 0 value case (n = 0)
        for i in range(m):
            table[0][i] = 1
    
        # Fill rest of the table entries in bottom up manner
        for i in range(1, n+1):
            for j in range(m):
    
                # Count of solutions including S[j]
                x = table[i - S[j]][j] if i-S[j] >= 0 else 0
    
                # Count of solutions excluding S[j]
                y = table[i][j-1] if j >= 1 else 0
    
                # total count
                table[i][j] = x + y
    
        return table[n][m-1]


import sys
sys.setrecursionlimit(10**6)

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n,m = list(map(int,input().strip().split()))
        S = list(map(int,input().strip().split()))
        ob = Solution()
        print(ob.count(S,m,n))
        
        