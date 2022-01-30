/*
Minimum number of jumps
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot 
move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
*/

	#include<bits/stdc++.h>
	using namespace std;

	class Solution{
 		public:
    			int minJumps(int arr[], int n){
        			// Your code here
        			// The number of jumps needed to reach the starting index is 0 
        			if (n <= 1) 
            				return 0; 
      
        			// Return -1 if not possible to jump 
        			if (arr[0] == 0) 
            				return -1; 
      
        			// initialization 
        			int maxReach = arr[0];  // stores all time the maximal reachable index in the array. 
        			int step = arr[0];      // stores the number of steps we can still take 
        			int jump =1;//stores the number of jumps necessary to reach that maximal reachable position. 
      
        			// Start traversing array 
        			int i=1; 
        			for (i = 1; i < n; i++){ 
            				// Check if we have reached the end of the array 
            				if (i == n-1) 
                				return jump; 
      
            				// updating maxReach 
            				maxReach = max(maxReach, i+arr[i]); 
      
            				// we use a step to get to the current index 
            				step--; 
      
            				// If no further steps left 
            				if (step == 0){ 
                				// we must have used a jump 
                				jump++; 
      
                				// Check if the current index/position or lesser index 
                				// is the maximum reach point from the previous indexes 
                				if(i >= maxReach) 
                    					return -1; 
      
                				// re-initialize the steps to the amount 
                				// of steps to reach maxReach from position i. 
                				step = maxReach - i; 
            				} 
        			} 
      
        			return -1; 
    			}
		};

	int main(){
    		int t;
    		cin>>t;
    		while(t--){
        		int n,i,j;
        		cin>>n;
        		int arr[n];
        		for(int i=0;i<n;i++){
            			cin>>arr[i];
        		}
        		Solution ob;
        		cout<<ob.minJumps(arr,n)<<endl;
    		}
    		return 0;
	}
