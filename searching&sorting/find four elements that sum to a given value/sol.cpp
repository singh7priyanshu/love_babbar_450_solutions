/*
find four elements that sum to a given value

Given an array of integers and another number. Find all the unique quadruple from 
the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function 
fourSum() which takes the array arr[] and the integer k as its input and returns an array 
containing all the quadruples in a lexicographical manner. Also note that all the quadruples 
should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should 
follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. 
The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100
 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        if(arr.size() < 4)return{};
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i = 0;i<arr.size()-3; i++){
            if(arr[i] > 0 && arr[i]>k)break;
            if(i>0 && arr[i] == arr[i-1])continue;
            for(int j = i+1;j<arr.size()-2;j++){
                if(j>i+1 && arr[j] == arr[j-1])continue;
                int left = j+1;
                int right = arr.size()-1;
                while(left<right){
                    int old_l = left;
                    int old_r = right;
                    int sum = arr[i]+arr[j]+arr[left]+arr[right];
                    if(sum == k){
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while(left<right && arr[left] == arr[old_l])left++;
                        while(left<right && arr[right] == arr[old_r])right--;
                    }
                    else if(sum > k)right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k, i;
        cin>>n>>k;
        vector<int>a(n);
        for(i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        vector<vector<int>>ans = ob.fourSum(a, k);
        for(auto &v : ans){
            for(int &u : v)cout<<u<<" ";
            cout<<"$"<<endl;
        }
        if(ans.empty())cout<<"-1"<<endl;
    }
    return 0;
}