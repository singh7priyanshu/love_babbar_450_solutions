/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

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

*/

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