/*
DIEHARD -DIE HARD

The game is simple. You initially have ‘H’ amount of health 
and ‘A’ amount of armor. 

At any instant you can live in any of the three places 
- fire, water and air. After every unit time, you have to 
change your place of living. For example if you are 
currently living at fire, you can either step into water 
or air.

If you step into air, your health increases by 3 
and your armor increases by 2

If you step into water, your health decreases by 5 
and your armor decreases by 10

If you step into fire, your health decreases by 20 
and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.

Input:

The first line consists of an integer t, the number of 
test cases. For each test case there will be two positive 
integers representing the initial health H and initial armor A.


Output:

For each test case find the maximum time you can survive.

 

Note: You can choose any of the 3 places during your first move.

 

Input Constraints:

1 <= t <= 10
1 <= H, A <= 1000

Example:

Sample Input:

3
2 10
4 4
20 8
Sample Output:

1
1
5
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int solve(int h, int a, int cnt,bool f)
{
    if( h<=0 || a<=0) return cnt;

    if(dp[h][a] != -1) return dp[h][a];
    if(f) dp[h][a] = max(dp[h][a], solve(h+3,a+2,cnt+1,!f));

    return dp[h][a] = max(dp[h][a], max(solve(h-5,a-10,cnt+1,!f),solve(h-20,a+5,cnt+1,!f)));
}

int main()
{   int tc;
    cin >> tc;
    int h,a;

    while(tc--){
    bool f=true;
    memset(dp,-1,sizeof dp);
    cin >> h >> a;

    cout << solve(h,a,-1,f) << endl;
}
   return 0;

}