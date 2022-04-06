/*
Maximum sum of absolute difference of an array

Given an array, we need to find the maximum sum of 
absolute difference of any permutation of the given array.

Examples: 
 

Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18

To solve this problem, we have to think greedily that 
how can we maximize the difference value of the elements 
so that we can have a maximum sum. This is possible only 
if we calculate the difference between some very high 
values and some very low values like (highest – smallest). 

This is the idea which we have to use to solve this problem. 

Let us see the above example, we will have maximum difference 
possible for sequence {1, 8, 2, 4} because in this sequence 
we will get some high difference values, ( |1-8| = 7, |8-2| = 6 .. ). 

Here, by placing 8(highest element) in place of 1 and 2 we 
get two high difference values. Similarly, for the other values, 
we will place next highest values in between other, as we have 
only one left i.e 4 which is placed at last. 

Algorithm: To get the maximum sum, we should have a sequence 
in which small and large elements comes alternate. 
This is done to get maximum difference.
For the implementation of the above algorithm -> 
1. We will sort the array. 
2. Calculate the final sequence by taking one smallest element 
    and largest element from the sorted array and make one 
    vector array of this final sequence. 
3. Finally, calculate the sum of absolute difference between 
    the elements of the array.
Below is the implementation of above idea : 
 
*/

// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array
	// so that we can retrieve
	// the large elements from
	// the end of array elements
	sort(a, a + n);

	// In this loop first we will insert
	// one smallest element not entered
	// till that time in final sequence
	// and then enter a highest element
	// (not entered till that time) in
	// final sequence so that we
	// have large difference value. This
	// process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2 because
	// we are inserting two elements at a
	// time in loop.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the
	// middle element at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);

	// variable to store the
	// maximum sum of absolute
	// difference
	int MaximumSum = 0;

	// In this loop absolute difference
	// of elements for the final sequence
	// is calculated.
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] -
								finalSequence[i + 1]);
	}

	// absolute difference of last element
	// and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] -
									finalSequence[0]);

	// return the value
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}

/*
Output : 

18
*/