/*
Find if there is any subarray with sum equal to 0

Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the drivers code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
-105 <= a[i] <= 105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n){
        unordered_map<int,bool>map;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum == 0 || map[sum] == true)return true;
            map[sum] = true;
        }
        return false;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        Solution obj;
        if(obj.subArrayExists(arr,n))cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}