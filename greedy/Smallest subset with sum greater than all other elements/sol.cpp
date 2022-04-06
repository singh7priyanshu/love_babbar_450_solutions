/*
Smallest subset with sum greater than all other elements

Given an array of non-negative integers. Our task is to 
find minimum number of elements such that their sum should 
be greater than the sum of rest of the elements of the array.
Examples : 
 

Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of
this subset is greater than all
other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not 
enough. We can pick elements with 
values 1, 2 or 2, 2. In any case, 
the minimum count is 2.

The Brute force approach is to find the sum of all the 
possible subsets and then compare sum with the sum of 
remaining elements.

The Efficient Approach is to take the largest elements. 

We sort values in descending order, then take elements 
from the largest, until we get strictly more than half 
of total sum of the given array. 

*/

// CPP program to find minimum number of
// elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// function to find minimum elements needed.
int minElements(int arr[], int n)
{
	// calculating HALF of array sum
	int halfSum = 0;
	for (int i = 0; i < n; i++)
		halfSum = halfSum + arr[i];
	halfSum = halfSum / 2;

	// sort the array in descending order.
	sort(arr, arr + n, greater<int>());

	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; i++) {

		curr_sum += arr[i];
		res++;

		// current sum greater than sum
		if (curr_sum > halfSum)		
			return res;
	}
	return res;
}

// Driver function
int main()
{
	int arr[] = {3, 1, 7, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minElements(arr, n) << endl;
	return 0;
}


/*
Output: 
 

1
Time Complexity : O(n Log n)
*/