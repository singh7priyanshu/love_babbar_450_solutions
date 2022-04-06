/*
Minimum sum of absolute difference of pairs of two arrays

Given two arrays a[] and b[] of equal length n. 
The task is to pair each element of array a to an element 
in array b, such that sum S of absolute differences of all 
the pairs is minimum.

Suppose, two elements a[i] and a[j] (i != j) of a are 
paired with elements b[p] and b[q] of b respectively, 
then p should not be equal to q.
Examples: 

Input :  a[] = {3, 2, 1}
         b[] = {2, 1, 3}
Output : 0
Explanation :
 1st pairing: |3 - 2| + |2 - 1| + |1 - 3|
         = 1 + 1 + 2 = 4
 2nd pairing: |3 - 2| + |1 - 1| + |2 - 3|
         = 1 + 0 + 1 = 2
 3rd pairing: |2 - 2| + |3 - 1| + |1 - 3|
         = 0 + 2 + 2 = 4
 4th pairing: |1 - 2| + |2 - 1| + |3 - 3|
         = 1 + 1 + 0 = 2
 5th pairing: |2 - 2| + |1 - 1| + |3 - 3|
         = 0 + 0 + 0 = 0
 6th pairing: |1 - 2| + |3 - 1| + |2 - 3|
         = 1 + 2 + 1 = 4
 Therefore, 5th pairing has minimum sum of
 absolute difference.

Input :  n = 4
         a[] = {4, 1, 8, 7}
         b[] = {2, 3, 6, 5}
Output : 6

The solution to the problem is a simple greedy approach. 

It consists of two steps. 
Step 1 : Sort both the arrays in O (n log n) time. 
Step 2 : Find absolute difference of each pair of 
    corresponding elements (elements at same index) of 
    both arrays and add the result to the sum S. 
    The time complexity of this step is O(n).

Hence, the overall time complexity of the program is O(n log n). 

*/


// C++ program to find minimum sum of absolute
// differences of two arrays.
#include <bits/stdc++.h>
using namespace std;
 
// Returns minimum possible pairwise absolute
// difference of two arrays.
long long int findMinSum(long long int a[],long long int b[], int n)
{
    // Sort both arrays
    sort(a, a+n);
    sort(b, b+n);
 
    // Find sum of absolute differences
    long long int sum= 0 ;
    for (int i=0; i<n; i++)
        sum = sum + abs(a[i]-b[i]);
 
    return sum;
}
 
// Driver code
int main()
{
    // Both a[] and b[] must be of same size.
    long long int a[] = {4, 1, 8, 7};
    long long int b[] = {2, 3, 6, 5};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%lld\n", findMinSum(a, b, n));
    return 0;
}
/*
Output :  

6
Time Complexity: O(n * logn)

Auxiliary Space: O(1)
*/