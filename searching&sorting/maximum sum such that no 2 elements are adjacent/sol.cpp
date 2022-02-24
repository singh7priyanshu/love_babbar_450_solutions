/*
maximum sum such that no 2 elements are adjacent

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

Constraints:
1 ≤ n ≤ 104
1 ≤ a[i] ≤ 104

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution{
    public:
    int FindMaxSum(int arr[], int n){
        int incl_curr = arr[0], excl_curr = 0, incl_prev = incl_curr, excl_prev =excl_curr;
        for(int i = 1;i<n;i++){
            excl_curr = max(incl_prev, excl_prev);
            incl_curr = excl_prev + arr[i];
            excl_prev = excl_curr;
            incl_prev = incl_curr;
        }
        return max(excl_curr, incl_curr);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.FindMaxSum(a, n)<<endl;
    }
    return 0;
}

