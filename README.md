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
	
	
### Sort an array of 0s, 1s and 2s
#### Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

##### cpp
	#include<bits/stdc++.h>
	using namespace std;
	
	class Solution{
    		public:
    		void sort012(int a[], int n){
        		// coode here 
        		int low = 0, high = n-1, mid = 0;
    			while(mid <= high){
    				if(a[mid]==0)
                			swap(a[mid++], a[low++]);
           			else if(a[mid]==1)
                 			mid++;
  				else
                			swap(a[mid], a[high--]);
        		}
    		}
    	};
		
	/driver code
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
			solution ob;
			ob.sort012(a,n);
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	
##### python
	class Solution:
    		def sort012(self,arr,n):
        		low=0
        		high=n-1
        		mid=0
        		while mid<=high:
            			if arr[mid]==0:
                			arr[mid] , arr[low] = arr[low] , arr[mid]
                			mid+=1
                			low+=1
            			elif arr[mid]==1:
                			mid+=1
           			else:
                			arr[mid] , arr[high] = arr[high] , arr[mid]
                			high-=1
					
	if __name__=='__main__':
		t=int(input())
		for _ in range(t):
			n=int(input())
			arr=[int(x) for x in input().strip().split()]
			ob=Solution()
			ob.sort012(arr,n)
			for i in arr:
				print(i, end=' ')
			print()
			
### Move all negative numbers to beginning and positive to end with constant extra space
#### An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.

##### cpp
	// A C++ program to put all negative
	// numbers before positive numbers
		#include <bits/stdc++.h>
		using namespace std;

		void rearrange(int arr[], int n){
			int j = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] < 0) {
					if (i != j)
						swap(arr[i], arr[j]);
					j++;
				}
			}
		}

	// A utility function to print an array
		void printArray(int arr[], int n){
			for (int i = 0; i < n; i++)
				printf("%d ", arr[i]);
		}

	// Driver code
		int main(){
			int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
			int n = sizeof(arr) / sizeof(arr[0]);
			rearrange(arr, n);
			printArray(arr, n);
			return 0;
		}
		
###### two pointer approach
	
	// C++ program of the above
	// approach

	#include <iostream>
	using namespace std;

	// Function to shift all the
	// negative elements on left side
	void shiftall(int arr[], int left, int right){
		// Loop to iterate over the
		// array from left to the right
		while (left<=right){
			// Condition to check if the left
			// and the right elements are
			// negative
			if (arr[left] < 0 && arr[right] < 0)
				left+=1;
	
			// Condition to check if the left
			// pointer element is positive and
			// the right pointer element is negative
			else if (arr[left]>0 && arr[right]<0){
				int temp=arr[left];
				arr[left]=arr[right];
				arr[right]=temp;
				left+=1;
				right-=1;
			}
	
			// Condition to check if both the
			// elements are positive
			else if (arr[left]>0 && arr[right] >0)
				right-=1;
			else{
				left += 1;
				right -= 1;
			}
		}
	}

	// Function to print the array
	void display(int arr[], int right){

		// Loop to iterate over the element
		// of the given array
		for (int i=0;i<=right;++i){
			cout<<arr[i]<<" ";
		}
	cout<<endl;
	}

	// Driver Code
	int main(){
		int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
		int arr_size = sizeof(arr) / sizeof(arr[0]);

		// Function Call
		shiftall(arr,0,arr_size-1);
		display(arr,arr_size-1);
		return 0;
	}

		
##### python
	# A Python 3 program to put
	# all negative numbers before
	# positive numbers

	def rearrange(arr, n ) :

		# Please refer partition() in
		# below post
		# https://www.geeksforgeeks.org / quick-sort / j = 0
		j = 0
		for i in range(0, n) :
			if (arr[i] < 0) :
				temp = arr[i]
				arr[i] = arr[j]
				arr[j]= temp
				j = j + 1
		print(arr)

	# Driver code
	arr = [-1, 2, -3, 4, 5, 6, -7, 8, 9]
	n = len(arr)
	rearrange(arr, n)

###### two pointer approach
	# Python3 program of the
	# above approach

	# Function to shift all the
	# the negative elements to
	# the left of the array
	def shiftall(arr,left,right):

		# Loop to iterate while the
		# left pointer is less than
		# the right pointer
		while left<=right:
	
			# Condition to check if the left
			# and right pointer negative
			if arr[left] < 0 and arr[right] < 0:
				left+=1
	
			# Condition to check if the left
			# pointer element is positive and
			# the right pointer element is
			# negative
			elif arr[left]>0 and arr[right]<0:
				arr[left], arr[right] = \ arr[right],arr[left]
				left+=1
				right-=1
	
			# Condition to check if the left
			# pointer is positive and right
			# pointer as well
			elif arr[left]>0 and arr[right]>0:
				right-=1
			else:
				left+=1
				right-=1
	
	# Function to print the array
	def display(arr):
		for i in range(len(arr)):
			print(arr[i], end=" ")
		print()

	# Driver Code
	if __name__ == "__main__":
		arr=[-12, 11, -13, -5,	6, -7, 5, -3, 11]
		n=len(arr)
		shiftall(arr,0,n-1)
		display(arr)



	
	



                    
                   
