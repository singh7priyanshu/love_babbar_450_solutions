/*
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

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        long long int table[n + 1];
        memset(table, 0, sizeof(table));
        table[0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = S[i]; j <= n; j++) table[j] += table[j - S[i]];

        return table[n];

    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.count(arr,m,n)<<endl;
    }
    return 0;
}