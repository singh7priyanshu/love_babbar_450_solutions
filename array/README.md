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
		
	
### Union of two arrays 
#### Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
Explanation: 
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.

##### cpp 

	#include<bits/stdc++.h>
	using namespace std;

	class Solution{
    		public:
    		//Function to return the count of number of elements in union of two arrays.
    		int doUnion(int a[], int n, int b[], int m)  {
        		//code here
        		//using set to store the elements.
        		unordered_set<int> s;
    	    
    			//we insert all the elements of first array in set.
    			for(int i = 0;i<n;i++)
    	   			s.insert(a[i]);
    	    
    	 		//we insert all the elements of second array in set.
    	 		//Set does not contain duplicates.
    	 		for(int i = 0;i<m;i++)
    	    			s.insert(b[i]);
    	    
    	  		//returning the size of set which is total number of elements in set.
    	  		return s.size() ;
		}
	};

	int main(){
    		int t;
    		cin>>t;
    		while(t--){
        		int n,m;
        		cin>>n>>m;
        		int a[n], b[m];
        		for(int i=0;i<n;i++){
            			cin>>a[i];
        		}
        		for(int i=0;i<m;i++){
            			cin>>b[i];
        		}
        		Solution ob;
        		cout<<ob.doUnion(a,n,b,m)<<endl;
    		}
    		return 0;
	}

##### python
	class Solution:    
    		#Function to return the count of number of elements in union of two arrays.
    		def doUnion(self,a,n,b,m):
        
        		#code here
        		#using set to store the elements.
        		hs=set() 
        
        		#we insert all the elements of first array in set.
        		for i in range(0,n): 
            			hs.add(a[i]) 
        
        		#we insert all the elements of second array in set.
    			#Set does not contain duplicates.
        		for i in range(0,m): 
            			hs.add(b[i]) 
        
        		#returning the size of set which is total number of elements in set.
        		return len(hs)

	#driver code 
	if __name__=='__main__':
  		t= int(input())
    		for _ in range(t):
        		n,m = [int(x) for x in input().strip().split()]
        		a = [int(x) for x in input().strip().split()]
        		b = [int(x) for x in input().strip().split()]
        		ob =  Solution()
        		print (ob.doUnion(a,n,b,m))
			
### Cyclically rotate an array by one
#### Given an array, rotate the array by one position in clock-wise direction.

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4

##### cpp 
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
	
##### python
	def rotate( arr, n):
  	  	x = arr[n - 1]
     		for i in range(n - 1, 0, -1):
        		arr[i] = arr[i - 1];
        	arr[0] = x;
    
	def main():
    		T = int(input())
    		while(T>0):
        		n = int(input())
        		a = [int(x) for x in input().strip().split()]
        		rotate(a,n)
        		print(*a)
        		T-=1

	if __name__ =="__main__":
    		main()
		
## Kadane's Algorithm
### Largest Sum Contiguous Subarray
#### Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.


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

##### cpp
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

##### python
	class Solution:
   	 	##Complete this function
    		#Function to find the sum of contiguous subarray with maximum sum.
    		def maxSubArraySum(self,arr,N):
        		##Your code here
        		max_so_far = -9999999 - 1
        		max_ending_here = 0
        
        		#Iterating over the array. 
        		for i in range(0, N): 
            			#Updating max sum till current index.
            			max_ending_here = max_ending_here + arr[i]
            
            			#Storing max sum so far by choosing maximum between max 
            			#sum so far and max sum till current index.
            			if (max_so_far < max_ending_here): 
                			max_so_far = max_ending_here 
        
            			#If max sum till current index is negative, we do not need to add
            			#it to result so we update it to zero.
            			if max_ending_here < 0: 
                			max_ending_here = 0   
        
        		#returning the result.
        		return max_so_far

	import math

	def main():
    		T = int(input())
    		while(T>0):
        		n = int(input())
        		arr = [int(x) for x in input().strip().split()]
        		ob = Solution
        		print(ob.maxSubArraySum(arr,n))
        		T-=1

	if __name__ == "__main__":
    		main()

### Minimize the Heights II
#### Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.

##### cpp
	#include<bits/stdc++.h>
	using namespace std;

	class Solution {
  		public:
   	 		int getMinDiff(int arr[], int n, int k) {
        			// code here
        			vector<pair<int, int>> v;
        			vector<int> taken(n);

        			// we will store all possible heights in a vector
        			for (int i = 0; i < n; i++) {
            				if (arr[i] - k >= 0) {
                				v.push_back({arr[i] - k, i});
            				}
           	 			v.push_back({arr[i] + k, i});
        			}
        			sort(v.begin(), v.end());
        			int elements_in_range = 0;
        			int left = 0;
        			int right = 0;

        			// By two pointer we will traverse v and whenever we will get a range
        			// in which all towers are included, we will update the answer.
        			while (elements_in_range < n && right < v.size()) {
            				if (taken[v[right].second] == 0) {
                				elements_in_range++;
            				}
            				taken[v[right].second]++;
            				right++;
        			}
        			int ans = v[right - 1].first - v[left].first;
        			while (right < v.size()) {
            				if (taken[v[left].second] == 1) {
                				elements_in_range--;
            				}
            				taken[v[left].second]--;
            				left++;

            				while (elements_in_range < n && right < v.size()) {
                				if (taken[v[right].second] == 0) {
                    					elements_in_range++;
                				}
                				taken[v[right].second]++;
                				right++;
            				}

            				if (elements_in_range == n) {
                				ans = min(ans, v[right - 1].first - v[left].first);
            				} else {
                				break;
            				}
        			}
        			return ans;
    			}
	};

	int main(){
    		int t;
    		cin>>t;
    		while(t--){
        		int n,k;
        		cin>>k>>n;
        		int arr[n];
        		for(int i=0; i<n; i++){
            			cin>>arr[i];
        		}
        		Solution ob;
        		auto ans = ob.getMinDiff(arr, n, k);
        		cout<<ans<<endl;
    		}
    		return 0;
	}
	
##### python

	class Solution:
    		def getMinDiff(self, arr, n, k):
        		# code here
        		v = []
        		taken = [0]*n
        
        		for i in range(n):
            			if arr[i]-k >= 0:
                			v.append([arr[i]-k,i])
            			v.append([arr[i] + k,i])
           		v.sort()
        
        		elements_in_range = 0;
        		left = 0
        		right = 0
        
        		while elements_in_range < n and right < len(v) :
            
            			if taken[v[right][1]] == 0 :
                			elements_in_range+=1;
            
            			taken[v[right][1]]+=1;
            			right+=1;
        
        
        		ans = v[right - 1][0] - v[left][0]
        
        		while right < len(v) :
    
            			if(taken[v[left][1]] == 1) :
               				elements_in_range-=1;
            
            			taken[v[left][1]]-=1;
           			left+=1
            
            			while elements_in_range < n and right < len(v) : 
                			if taken[v[right][1]] == 0 :
                    				elements_in_range+=1
                
                			taken[v[right][1]]+=1
                			right+=1
            
            
            			if(elements_in_range == n) : 
                			ans = min(ans, v[right - 1][0] - v[left][0])
            			else :
                			break
            		return ans
	
	if __name__=="__main__":
    		tc =  int(input())
    		while tc > 0:
        		k = int(input())
        		n = int(input())
        		arr = list(map(int, input().strip().split()))
        		ob = Solution()
        		ans = ob.getMinDiff(arr, n ,k)
        		print(ans)
        		tc-=1   
                
### Minimum number of jumps
#### Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
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

##### cpp
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
           
##### python
	class Solution:
		def minJumps(self, arr, n):
	    		#code here
	    		if len(arr) <= 1 : 
            			return 0 
  
        		# Return -1 if not possible to jump 
        		if arr[0] == 0 :  
            			return -1 
  
        		# initialization 
        		maxReach = arr[0]; 
        		step = arr[0]; 
       			jump = 1; 
  
  
        		# Start traversing array 
        		for i in range(1,len(arr)):

            			# Check if we have reached the end of the array 
            			if  i == len(arr) - 1 : 
                			return jump 
  
            			# updating maxReach 
           	 		maxReach = max(maxReach, i+arr[i])
  
            			# we use a step to get to the current index 
            			step-=1; 
  
            			# If no further steps left 
            			if  step == 0 : 
                			#  we must have used a jump 
                			jump+=1 
                   
                			#Check if the current index/position  or lesser index 
                			#is the maximum reach point from the previous indexes 
                			if i>=maxReach : 
                   				return -1
  
                			#re-initialize the steps to the amount 
                			#of steps to reach maxReach from position i. 
                			step = maxReach - i 
  
        		return -1

	if __name__=="__main__":
    		T = int(input())
    		for i in range(T):
        		n = int(input())
        		Arr = [int(x) for x in input().split()]
        		ob = Solution()
       	 		ans = ob.minJumps(Arr, n)
        		print(ans)  

### Find the Duplicate Number
#### Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

#### Let's take an example where the array is not ordered, the duplicate is repeated more than once. E.g., the array a = [ 2, 7, 4, 5, 1, 6, 4, 3, 8, 4 ].
Since we could use O(1) extra space, the indices of the array becomes more important for us. Given the indices, this problem becomes finding the indices which are targeting the same value. Note that, the indices are from 0 to n, and the values are from 1 to n. We could consider both the indices and values are nodes in one linked list, and the array (or the index-value pair) represents the connections between the nodes. Thus the array can be converted into a linked list.

Given the linked list, it is not hard to notice that, the duplicates value in array now becomes a loop in the linked list. So, to find if there is a loop (and also the circle strat node), we could use slow and fast pointers which we have seen before:

Loop detection: If the fast pointer catch up the slow pointer at the same node, there must be a loop.
Find the loop start node: The distance from head node to the loop start node, and the distance from catchup node to the loop start node, are the same.
So, the last question is how to determine the start point of the linked list. We could use the 1st element, since the index of 1st element in array is always 0, and there is no 0 in the value (it starts from 1). So it is impossible that 1st is in the loop.

##### cpp
	class Solution {
	public:
    		int findDuplicate(vector<int>& nums) {
        		if (nums.size() > 1){
              			int slow = nums[0];
              			int fast = nums[nums[0]];
              			while (slow != fast){
                  			slow = nums[slow];
                  			fast = nums[nums[fast]];
              			}

            		fast = 0;
            		while (fast != slow){
                  		fast = nums[fast];
                  		slow = nums[slow];
            		}
            		return slow;
        	}
        	return -1;
	};
	
##### python

	class Solution(object):
    		def findDuplicate(self, nums):
        		"""
        		:type nums: List[int]
        		:rtype: int
        		"""
        		if len(nums) > 1:
           	 		slow = nums[0]
            			fast = nums[nums[0]]
            			while slow != fast:
                			slow = nums[slow]
                			fast = nums[nums[fast]]
            			fast = 0
            			while slow != fast:
                			slow = nums[slow]
                			fast = nums[fast]
            			return slow
        
        		return -1

### Merge Without Extra Space
#### Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


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

##### cpp
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
			for(i=0;i<n;i++){
				cin>>arr1[i];
			}
			for(j=0;j<m;j++){
				cin>>arr2[j];
			}
			Solution ob;
			ob.merge(arr1, arr2, n, m);
			for(i=0;i<n;i++){
				cout<<arr1[i]<<" ";
			}
			for(i=0;i<m;j++){
				cout<<arr2[i]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	
##### python
	class Solution:
    		def nextGap(self,gap):
        
        		#It returns the ceil value of gap/2 or 0 if gap is 1.
        		if(gap<=1):
            			return 0
        		return ((gap+1)//2)
        
    		def merge(self, arr1, arr2, n, m): 
        		# code here
        		gap=n+m
        		gap = self.nextGap(gap)
        		while(gap>0):
            			i=0
            
            			#Comparing elements in the first array itself with difference in 
    	    			#index equal to the value of gap.
            			while(i+gap<n):
                
                			#If element at ith index is greater than element at
    		    			#(i+gap)th index, we swap them.
                			if(arr1[i]>arr1[i+gap]):
                    				arr1[i],arr1[i+gap]=arr1[i+gap],arr1[i]
                			i+=1
    
            			j = max(0, gap - n)
            
            			#Now comparing elements in both arrays with help of two pointers.
    				#The loop stops whenever any pointer exceeds the size of its array.
            			while(i<n and j<m):
                
                			#If element in the first array is greater than element in
    		    			#second array, we swap them.
                			if(arr1[i]>arr2[j]):
                    				arr1[i],arr2[j]=arr2[j],arr1[i]
                			i+=1
                			j+=1
        
            			if(j<m):
                			j=0
                
                			#At last, comparing elements in the second array itself with 
                			#difference in index equal to the value of gap.
                			while(j+gap < m):
                    
                    				#If element at jth index is greater than element at
    		        			#(j+gap)th index, we swap them.
                    				if (arr2[j] > arr2[j + gap]):
                        				arr2[j], arr2[j + gap] = arr2[j + gap], arr2[j]
                    				j+=1
                    
            			#Updating the value of gap.        
            			gap = self.nextGap(gap)
				
	if __name__ == "__main__":
		tc = int(input())
		while tc > 0:
			n, m = map(int ,(input().strip().split()))
			arr1 = list(map(int, input().strip().split()))
			arr2 = list(map(int, input().strip().split()))
			ob = Solution()
			ans = ob.merge(arr1, arr2, n, m)
			for x in arr1:
				print(x, end = " ")
			for x in arr2:
				print(x, end = " ")
			print()
			tc = tc-1
