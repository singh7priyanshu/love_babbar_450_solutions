# lovebabbarreadingmaterial
## Arrays
### Write a program to reverse an array or string
##### cpp
	#include <iostream>
	using namespace std;

	int main() {
		int t;
		cin>>t;
		while(t--){
	    		string s;
	    		cin>>s;
	    		int n = s.length();
	    		for(int i = 0; i < n/2; i++){
	        	swap(s[i],s[n-1-i]);
	    		}
	    		cout<<s<<endl;
		}
		return 0;
	}
##### python
	class Solution:
    		def reverseWord(s):
        		# for reversing the array we will traverse it from 0th index to the mid index
        		# and keep swapping the ith index value with (len(s)-i)th index value
        		l=len(s)
      			for i in range(len(s)//2):
            			s[i],s[l-i-1] = s[l-i-1],s[i]
 			return(s)
			
### Maximum and minimum of an array using minimum number of comparisons	
##### cpp
	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int n;
		cout<<"Enter array size"<<endl;
		cin>>n;
		int arr[n];
		cout<<"Enter array"<<endl;
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		int mn = INT_MAX, mx = INT_MIN;
		for(int i = 0; i < n; i++){
			if(arr[i] < mn)
				mn = arr[i];
			if(arr[i] > mx)
				mx = arr[i];
			}
		cout<<"Minimum element found :"<<mn<<endl;
		cout<<"Maximum element found :"<<mx<<endl;
		return 0;
	}
##### python
	def min_max_elements(A):
    		A = sorted(arr)
    		minimum_element = A[0]
    		maximum_element = A[-1]
    		return (minimum_element, maximum_element)
		
### Kth smallest element
#### Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
##### cpp
	#include <bits/stdc++.h>
	using namespace std;
	signed main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//using priority queue - nlogn	
		//using sorting - nlogn
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int k;
		cin >> k;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			pq.push(a[i]);
			if ((int)pq.size() > k) {
				pq.pop();
			}
		}	
    		cout << pq.top();
		return 0;
	} 
##### python
	def kth_min_max(A, k):
    		A = sorted(A)
    		kth_min = A[k-1]  # k-th element from the beginning of sorted array
    		kth_max = A[-k]  # k-th element from the end of sorted array
    		return (kth_min, kth_max)
	# kth_min_max([-1, 10, -5, 30, -8, 40, 60], 3) --> (-1, 30)
                    
                   
