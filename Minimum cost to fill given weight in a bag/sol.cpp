/*
Minimum cost to fill given weight in a bag

Given an array cost[] of positive integers of size N 
and an integer W, cost[i] represents the cost of ‘i’ kg 
packet of oranges, the task is to find the minimum cost 
to buy W kgs of oranges. If it is not possible to buy 
exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is 
    unavailable
2. It may be assumed that there is infinite supply of 
    all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 
Example 2:

Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges

Your Task:  
You don't need to read input or print anything. 
Complete the function minimumCost() which takes N, W, and 
array cost as input parameters and returns the minimum value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N, W ≤ 2*102
-1 ≤ cost[i] ≤ 105
cost[i] ≠ 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int minimumCost(int cost[], int N, int W){ 
        int INF = 999999999;
        vector<int>val, wt;
        int size = 0;
        for(int i = 0;i<N;i++){
            if(cost[i] != -1){
                val.push_back(cost[i]);
                wt.push_back(i+1);
                size++;
            }
        }
        N = size;
        int min_cost[N+1][W+1];
        for(int i = 0;i<=W;i++)min_cost[0][i] = INF;
        for(int i = 1;i<=N;i++)min_cost[i][0] = 0;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=W;j++){
                if(wt[i-1]>j)min_cost[i][j] = min_cost[i-1][j];
                else min_cost[i][j] = min(min_cost[i-1][j],
                                            min_cost[i][j-wt[i-1]]+val[i-1]);
            }
        }
        return (min_cost[N][W] == INF)? -1: min_cost[N][W];
	} 
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.minimumCost(a, n, w)<<endl;
    }
}