/*
Merge Without Extra Space
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

*/

	#include<bits/stdc++.h>
	using namespace std;
	
	class Solution{
	public:
	int nextGap(int gap){
		if(gap<=1)
			return 0;
		return (gap/2)+(gap%2);
	}
	void merge(int arr1[], int arr2[], int n, int m){
		int i, j, gap = n+m;
		for(gap = nextGap(gap); gap>0; gap=nextGap(gap)){
			// comparing elements in the first array itself with difference in
			// index equal to the value of the gap.
			for(i = 0; i + gap < n; i++)
				// if element at ith index is greater than element at
				// (i+gap)th index, we swap them.
				if(arr1[i]>arr1[i+gap])
					swap(arr1[i],arr1[i+gap]);
			// now comparing elements in both arrays with help of two pointers.
			// the loop stops whenever any pointer exceeds the size of its array.
			for(j = gap > n? gap-n : 0 ; i < n&&j < m; i++, j++)
				// if element in the first array is greater than element in
				// second array, we swap them.
				if(arr1[i] > arr2[j])
					swap(arr1[i], arr2[j]);
			if(j<m){
				// at last, comparing elements in the second array itself with 
				// difference in index equal to the value of the gap.
				for(j = 0 ; j+gap < m ; j++)
					// if element at jth index is greater than element at
					// (j+gap)th index, we swap them.
					if(arr2[j]>arr2[j+gap])
						swap(arr2[j],arr2[j+gap]);
				}
			}
		}
	};
	
	int main(){
		int t;
		cin>>t;
		while(t--){
			int n, m, i;
			cin>>n>>m;
			int arr1[n], arr2[m];
			for(int i=0;i<n;i++){
				cin>>arr1[i];
			}
			for(int j=0;j<m;j++){
				cin>>arr2[j];
			}
			Solution ob;
			ob.merge(arr1, arr2, n, m);
			for(i=0;i<n;i++){
				cout<<arr1[i]<<" ";
			}
			for(i=0;i<m;i++){
				cout<<arr2[i]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}