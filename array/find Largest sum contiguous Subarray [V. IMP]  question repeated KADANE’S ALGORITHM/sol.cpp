/*
Kadane's Algorithm
Largest Sum Contiguous Subarray
Given an array Arr[] of N integers. Find the contiguous sub-array
(containing at least one number) which has the maximum sum 
and return its sum.


Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

*/

	#include<bits/stdc++.h>
	using namespace std;

	class Solution{	
    		public:
   	 	// arr: input array
    		// n: size of array
    		//Function to find the sum of contiguous subarray with maximum sum.
    		long long maxSubarraySum(int arr[], int n){
        		
			// Your code here
        		long long maxh = 0, maxf = arr[0];
        
        		//Iterating over the array.
        		for(int i=0;i<n;i++){
			
                		//Updating max sum till current index.
                		maxh+=arr[i];
               		 	//Storing max sum so far by choosing maximum between max 
                		//sum so far and max till current index.
                		if(maxf<maxh)
                		maxf=maxh; 
                
                		//If max sum at current index is negative, we do not need to add
                		//it to result so we update it to zero.
                		if(maxh<0)
                    			maxh=0;
    		       	}
            		//returning the result.
            		return maxf;
    		}
	};

	int main(){
    		int t,n;
    		cin>>t;
    		while(t--){
        		cin>>n  ;
        		int a[n];
        		for(int i=0;i<n;i++){
            		cin>>a[i];
			}
        	Solution ob;
        	cout<<ob.maxSubarraySum(a,n)<<endl;
    		}
	}
