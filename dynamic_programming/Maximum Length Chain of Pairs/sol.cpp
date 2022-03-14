/*
Maximum Length Chain of Pairs

You are given N pairs of numbers. In every pair, 
the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. 
Chain of pairs can be formed in this fashion.

You have to find the longest chain which can be formed 
from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

Example 2:

Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.
 

Your Task:
You don't need to read input or print anything. 
Your task is to Complete the function maxChainLen() 
which takes a structure p[] denoting the pairs and n as 
the number of pairs and returns the length of the longest 
chain formed.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=100
*/

#include<bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        val p[n];
        for(int i = 0;i<n;i++)cin>>p[i].first>>p[i].second;
        cout<<maxChainLen(p, n)<<endl;
    }
    return 0;
}



bool cmp(struct val p1, struct val p2){
    if(p1.first<p2.first)return 1;
    else if (p1.first == p2.first && p1.second<p2.second)return 1;
    return 0;
}
int dp[10001];
int maxChainLen(struct val p[], int n){
    sort(p, p+n, cmp);
    for(int i = 0;i<10001;i++)dp[i] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(p[i].first>p[j].second && dp[i]<dp[j]+1)dp[i] = dp[j]+1;
        }
    }
    int m = INT_MIN;
    for(int i = 0;i<n;i++) m = max(dp[i], m);
    return m;
}