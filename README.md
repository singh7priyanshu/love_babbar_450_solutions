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
                    
                   
