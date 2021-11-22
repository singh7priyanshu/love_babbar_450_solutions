/*
Value equal to index value

Given an array Arr of N positive integers. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing ).

Example 1:

Input: 
N = 5
Arr[] = {15, 2, 45, 12, 7}
Output: 2
Explanation: Only Arr[2] = 2 exists here.
Example 2:

Input: 
N = 1
Arr[] = {1}
Output: 1
Explanation: Here Arr[1] = 1 exists.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function valueEqualToIndex() which takes the array of integers arr[] and n as parameters and returns an array of indices where the given conditions are satified. When there is not such element exists then return an empty array of length 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Note: There can be more than one element in the array which have same value as their index. You need to include every such element's index. Follows 1-based indexing of the array.

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int>sol;
	    for(int i=0;i<n;i++){
	        if(arr[i] == i+1){
	            sol.push_back(i+1);
	        }
	    }
	    return sol;
	}
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i =0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr,n);
        if(ans.empty()){
            cout<<"Not Found";
        }else{
            for(int x:ans){
                cout<<x<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}