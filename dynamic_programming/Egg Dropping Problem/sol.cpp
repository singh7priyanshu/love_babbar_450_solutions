/*
Egg Dropping Problem

You are given N identical eggs and you have access 
to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that 
any egg dropped at a floor higher than f will break, 
and any egg dropped at or below floor f will not break. 
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, 
    it will not break at any floor below.
If the eggs breaks at a certain floor, 
    it will break at any floor above.
Return the minimum number of moves that you need to 
determine with certainty what the value of f is.

For more description on this problem see wiki page
https://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two 
positive integer N and K as input parameters and 
returns the minimum number of attempts you need in 
order to find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int eggDrop(int n, int k){
        int eggFloor[n+1][k+1], res, i, j, x;
        for(i = 1;i<=n;i++){
            eggFloor[i][1] = 1;
            eggFloor[i][0] = 0;
        }
        for(j = 1;j<=k;j++)eggFloor[1][j] = j;
        for(i = 2;i<=n;i++){
            for(j = 2;j<=k;j++){
                eggFloor[i][j] = INT_MAX;
                for(x = 1;x<=j;x++){
                    res = 1+max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                    if(res<eggFloor[i][j])eggFloor[i][j] = res;
                }
            }
        }
        return eggFloor[n][k];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}