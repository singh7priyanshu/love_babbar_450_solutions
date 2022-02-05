/*

Median of 2 sorted arrays of different size

Efficient solution: 

 

Approach:The idea is simple, calculate the median of both the arrays and discard one
half of each array. 

Now, there are some basic corner cases. For array size less than or equal to 2 

Suppose there are two arrays and the size of both the arrays is greater than 2. 

Find the middle element of the first array and middle element of the second array 
(the first array is smaller than the second) if the middle element of the smaller 
array is less than the second array, then it can be said that all elements of the 
first half of smaller array will be in the first half of the output (merged array). 
So, reduce the search space by ignoring the first half of the smaller array and the 
second half of the larger array. Else ignore the second half of the smaller array and 
first half of a larger array.

In addition to that there are more basic corner cases: 

 

If the size of smaller array is 0. Return the median of a larger array.
if the size of smaller array is 1. 
The size of the larger array is also 1. Return the median of two elements.
If the size of the larger array is odd. Then after adding the element from 2nd array, 
it will be even so the median will be an average of two mid elements. So the element from 
the smaller array will affect the median if and only if it lies between (m/2 – 1)th and 
(m/2 + 1)th element of the larger array. So, find the median in between the four elements, 
the element of the smaller array and (m/2)th, (m/2 – 1)th and (m/2 + 1)th element of a larger array

Similarly, if the size is even, then check for the median of three elements, the element 
of the smaller array and (m/2)th, (m/2 – 1)th element of a larger array

If the size of smaller array is 2 
If the larger array also has two elements, find the median of four elements.
If the larger array has an odd number of elements, then the median will be one of the 
following 3 elements 
Middle element of larger array
Max of the second element of smaller array and element just before the middle, 
i.e M/2-1th element in a bigger array
Min of the first element of smaller array and element 
just after the middle in the bigger array, i.e M/2 + 1th element in the bigger array
If the larger array has even number of elements, then the median will be one of the following 4 elements 
The middle two elements of the larger array
Max of the first element of smaller array and element just before the first middle element in 
the bigger array, i.e M/2 – 2nd element
Min of the second element of smaller array and element just after the second middle in the bigger 
array, M/2 + 1th element
 

How can one half of each array be discarded?

 

Let’s take an example to understand this
Input :arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
brr[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 }
Dry Run of the code:
Recursive call 1:
smaller array[] = 1 2 3 4 5 6 7 8 9 10, mid = 5
larger array[] = 11 12 13 14 15 16 17 18 19 , mid = 15

5 < 15
Discard first half of the first array and second half of the second array

Recursive call 2:
smaller array[] = 11 12 13 14 15, mid = 13
larger array[] = 5 6 7 8 9 10, mid = 7

7 < 13
Discard first half of the second array and second half of the first array

Recursive call 3:
smaller array[] = 11 12 13 , mid = 12
larger array[] = 7 8 9 10 , mid = 8

8 < 12
Discard first half of the second array and second half of the first array

Recursive call 4:
smaller array[] = 11 12
larger array[] = 8 9 10

Size of the smaller array is 2 and the size of the larger array is odd
so, the median will be the median of max( 11, 8), 9, min( 10, 12)
that is 9, 10, 11, so the median is 10.

Output:10.000000

 

Algorithm: 

 

Create a recursive function that takes two arrays and the sizes of both the arrays.
Take care of the base cases for the size of arrays less than 2. (previously discussed in Approach).
Note: The first array is always the smaller array.
Find the middle elements of both the arrays. i.e element at (n – 1)/2 and (m – 1)/2 of first and 
second array respectively. Compare both the elements.

If the middle element of the smaller array is less than the middle element of the larger array 
then the first half of the smaller array is bound to lie strictly in the first half of the merged 
array. It can also be stated that there is an element in the first half of the larger array and 
the second half of the smaller array which is the median. So, reduce the search space to the first 
half of the larger array and the second half of the smaller array.
Similarly, If the middle element of the smaller array is greater than the middle element 
of the larger array then reduce the search space to the first half of the smaller array and 
second half of the larger array.


*/

// A C++ program to find median of two sorted arrays of
// unequal sizes
/*

Complexity Analysis: 

Time Complexity: O(min(log m, log n)). 
In each step one half of each array is discarded. 
So the algorithm takes O(min(log m, log n)) time to reach the median value.
Space Complexity: O(1). 
No extra space is required.
*/

#include <bits/stdc++.h>
using namespace std;

// A utility function to find median of two integers
float MO2(int a, int b)
{ return ( a + b ) / 2.0; }

// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
	return a + b + c - max(a, max(b, c))
					- min(a, min(b, c));
}

// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
	int Max = max( a, max( b, max( c, d ) ) );
	int Min = min( a, min( b, min( c, d ) ) );
	return ( a + b + c + d - Max - Min ) / 2.0;
}

// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
if (n == 0)
	return -1;
if (n%2 == 0)
		return (double)(arr[n/2] + arr[n/2-1])/2;
return arr[n/2];
}

// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil( int A[], int N, int B[], int M )
{
	// If smaller array is empty, return median from second array
	if (N == 0)
	return medianSingle(B, M);

	// If the smaller array has only one element
	if (N == 1)
	{
		// Case 1: If the larger array also has one element,
		// simply call MO2()
		if (M == 1)
			return MO2(A[0], B[0]);

		// Case 2: If the larger array has odd number of elements,
		// then consider the middle 3 elements of larger array and
		// the only element of smaller array. Take few examples
		// like following
		// A = {9}, B[] = {5, 8, 10, 20, 30} and
		// A[] = {1}, B[] = {5, 8, 10, 20, 30}
		if (M & 1)
			return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );

		// Case 3: If the larger array has even number of element,
		// then median will be one of the following 3 elements
		// ... The middle two elements of larger array
		// ... The only element of smaller array
		return MO3( B[M/2], B[M/2 - 1], A[0] );
	}

	// If the smaller array has two elements
	else if (N == 2)
	{
		// Case 4: If the larger array also has two elements,
		// simply call MO4()
		if (M == 2)
			return MO4(A[0], A[1], B[0], B[1]);

		// Case 5: If the larger array has odd number of elements,
		// then median will be one of the following 3 elements
		// 1. Middle element of larger array
		// 2. Max of first element of smaller array and element
		// just before the middle in bigger array
		// 3. Min of second element of smaller array and element
		// just after the middle in bigger array
		if (M & 1)
			return MO3 ( B[M/2],
						max(A[0], B[M/2 - 1]),
						min(A[1], B[M/2 + 1])
					);

		// Case 6: If the larger array has even number of elements,
		// then median will be one of the following 4 elements
		// 1) & 2) The middle two elements of larger array
		// 3) Max of first element of smaller array and element
		// just before the first middle element in bigger array
		// 4. Min of second element of smaller array and element
		// just after the second middle in bigger array
		return MO4 ( B[M/2],
					B[M/2 - 1],
					max( A[0], B[M/2 - 2] ),
					min( A[1], B[M/2 + 1] )
				);
	}

	int idxA = ( N - 1 ) / 2;
	int idxB = ( M - 1 ) / 2;

	/* if A[idxA] <= B[idxB], then median must exist in
		A[idxA....] and B[....idxB] */
	if (A[idxA] <= B[idxB] )
	return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );

	/* if A[idxA] > B[idxB], then median must exist in
	A[...idxA] and B[idxB....] */
	return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}

// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian( int A[], int N, int B[], int M )
{
	if (N > M)
	return findMedianUtil( B, M, A, N );

	return findMedianUtil( A, N, B, M );
}

// Driver program to test above functions
int main()
{
	int A[] = {900};
	int B[] = {5, 8, 10, 20};

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	printf("%f", findMedian( A, N, B, M ) );
	return 0;
}

/*

Binary Search

Approach: The given two arrays are sorted, so we can utilize the ability of Binary 
Search to divide the array and find the median.

Median means the point at which the whole array is divide into two parts. 
Hence since the two arrays are not merged so to get the median we require merging 
which is costly. Hence instead of merging we will use below given algorithm to 
efficiently find median.

1. Lets assume that there are two arrays A and B with array A having the minimum number of elements.
   If this is not the case than swap A and B to make A having small size.
2. The edge cases like one array is empty or both are empty will be handled.
3. let n be the size of A and m be the size of B.
   Now think of an idea that if we have to find the median than we have to divide the whole merged array into two parts
   namely left and right parts.
   Now since we are given the size of left part (i.e (n+m+1)/2), Now look at below given example.
   
       A-> 1,2,3,4,5     n = 5
       B-> 1,2,3,4,5,6   m = 6
   
    Here merged array will look like :- 1,1,2,2,3,3,4,4,5,5,6 and median then is 3
    
    Now we can see our left part which is underlined. We divide A and B into two parts such that the 
    sum of left part of both A and B will result in left part of merged array.
    
    A-> 1,2,3,4,5     // pointers l =0 and r = n-1 hence mid = (l+r)/2;
       B -> 1,2,3,4,5,6

    we can see that left part of A is given as n/2 and since total length of left part in merged array
    is (m+n+1)/2, so left part of B = (m+n+1)/2-n/2;
    
    Now we just have to confirm if our left and right partitions in A and B are correct or not.
    
4. Now we have 4 variables indicating four values two from array A and two from array B.
    leftA -> Rightmost element in left part of A = 2
    leftb -> Rightmost element in left part of B = 4
    rightA -> Leftmost element in right part of A = 3
    rightB -> Leftmost element in right part of B = 5
    
    Hence to confirm that partition is correct we have to check the following conditions.
    leftA<=rightB and leftB<=rightA  // This is the case when the sum of two parts of A and B results in left part of merged array
    
    if our partition not works that means we have to  find other mid point in A and then left part in B
    This is seen when
     
    leftA > rightB    //means we have to dec size of A's partition
    so do r = mid-1;
    else
        do l =mid+1;
    
    Hence repeat the above steps with new partitions till we get the answers.
5. If leftA<=rightB and leftB<=rightA
    then we get correct partition and our answer depends on the total size of merged array (i.e. m+n)
    
    If (m+n)%2==0
     ans is max(leftA,leftB)+min(rightA,rightB)/2; // max of left part is nearest to median and min of right part is nearest to medain
    else
     ans is max(leftA,leftB);


*/

/*
Time Complexity: O(min(log m, log n)) : Since binary search is being applied on the 
smaller of the 2 arrays
Auxiliary Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
	int n = A.size();
	int m = B.size();
	if (n > m)
		return Median(B, A); // Swapping to make A smaller

	int start = 0;
	int end = n;
	int realmidinmergedarray = (n + m + 1) / 2;

	while (start <= end) {
		int mid = (start + end) / 2;
		int leftAsize = mid;
		int leftBsize = realmidinmergedarray - mid;
		int leftA
			= (leftAsize > 0)
				? A[leftAsize - 1]
				: INT_MIN; // checking overflow of indices
		int leftB
			= (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
		int rightA
			= (leftAsize < n) ? A[leftAsize] : INT_MAX;
		int rightB
			= (leftBsize < m) ? B[leftBsize] : INT_MAX;

		// if correct partition is done
		if (leftA <= rightB and leftB <= rightA) {
			if ((m + n) % 2 == 0)
				return (max(leftA, leftB)
						+ min(rightA, rightB))
					/ 2.0;
			return max(leftA, leftB);
		}
		else if (leftA > rightB) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return 0.0;
}

// Driver code
int main()
{
	vector<int> arr1 = { -5, 3, 6, 12, 15 };
	vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
	cout << "Median of the two arrays are" << endl;
	cout << Median(arr1, arr2);
	return 0;
}
