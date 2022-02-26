/*
print all subarrays with 0 sum

You are given an array arr[] of size n. Find the total count of sub-arrays having 
their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() 
that takes the array arr and its size n as input parameters and returns the total 
number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public:
    ll findSubarray(vector<ll> arr, int n ) {
        ll sum = 0, counter = 0;
        unordered_map<ll, ll>mp;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum==0)counter++;
            if(mp.count(sum)!= 0)counter+=mp[sum];
            mp[sum]++;
        }
        return counter;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll>arr(n, 0);
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.findSubarray(arr, n)<<endl;
    }
    return 0;
}

/*
map_name.count(key k)
Parameters: The function accepts a mandatory parameter k which specifies the key 
to be searched in the map container.

Return Value: The function returns the number of times the key K is present in 
the map container. It returns 1 if the key is present in the container as the map 
only contains a unique key. It returns 0 if the key is not present in the map container.

*/
