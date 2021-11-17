/*
Cyclically rotate an array by one
Given an array, rotate the array by one position in clock-wise direction.

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4

*/

	#include<bits/stdc++.h>
	using namespace std;
	void rotate(int arr[], int n);

	int main(){
    		int t;
    		cin>>t;
    		while(t--){
        		int n;
        		cin>>n;
        		int a[n];
        		for(int i=0;i<n;i++){
            			cin>>a[i];
        		}
        		rotate(a,n);
        		for(int i=0; i<n; i++){
            			cout<<a[i]<<endl;
        		}
    		}
    		return 0;	
	}

	void rotate(int arr[], int n){
		int x = arr[n-1], i;
  	 	for (i = n-1; i > 0; i--)
      		arr[i] = arr[i-1];
   		arr[0] = x;
    	}