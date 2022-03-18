/*
Count number of ways to reacha given score in a game

Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of distinct combinations 
to reach the given score.

Example:
Input
3
8
20
13
Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the 
two possible permutations but 
these represent the same 
cobmination. Hence output is 1.
Your Task:  
You don't need to read input or print anything. Your task is to 
complete the function count( ) which takes N as input parameter 
and returns the answer to the problem.

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll count(ll n){
	ll table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 
	for(i = 3;i<=n;i++)table[i] += table[i-3];
	for(i = 5;i<=n;i++)table[i] += table[i-5];
	for(i = 10;i<=n;i++)table[i] += table[i-10];
	return table[n];
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        cout<<count(n)<<endl;
    }
}
