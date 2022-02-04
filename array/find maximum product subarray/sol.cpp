/*
find maximum product subarray 

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
Note: Use 64-bit integer data type to avoid overflow.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 500
-102 ≤ Arri ≤ 102

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long minVal = arr[0];
	    long long maxVal = arr[0];
	    long long maxProduct = arr[0];
	    for(int i = 1;i<n;i++){
	        if(arr[i]<0)swap(maxVal,minVal);
	        maxVal = max((long long)arr[i], maxVal*arr[i]);
	        minVal = min((long long)arr[i], minVal*arr[i]);
	        maxProduct = max(maxProduct, maxVal);
	    }
	    return maxProduct;
	}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, i;
        cin>>n;
        vector<int>arr(n);
        for(i=0;i<n;i++)cin>>arr[i];
        Solution ob;
        auto ans = ob.maxProduct(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}