/*
Implement Merge-sort in-place

Implement Merge Sort i.e. standard implementation keeping the 
sorting algorithm as in-place. 
In-place means it does not occupy extra memory for merge operation 
as in the standard case.

Examples: 

Input: arr[] = {2, 3, 4, 1} 
Output: 1 2 3 4

Input: arr[] = {56, 2, 45} 
Output: 2 45 56 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
 
Approach 1:

Maintain two pointers that point to the start of the segments which have to be merged.
Compare the elements at which the pointers are present.
If element1 < element2 then element1 is at right position, simply increase pointer1.
Else shift all the elements between element1 and element2
(including element1 but excluding element2) right by 1 and then place the 
element2 in the previous place(i.e. before shifting right) of element1. 
Increment all the pointers by 1.
Below is the implementation of the above approach:
*/

// C++ program in-place Merge Sort
#include <iostream>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void merge(int arr[], int start, int mid, int end)
{
    int start2 = mid + 1;
 
    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) {
        return;
    }
 
    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
 
        // If element 1 is in right place
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else {
            int value = arr[start2];
            int index = start2;
 
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
 
            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
 
        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< A[i];
    cout <<"\n";
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printArray(arr, arr_size);
    return 0;
}
 
/*
Output
5 6 7 11 12 13 
Note: Time Complexity of above approach is O(n2 * log(n)) because merge is O(n2). 
Time complexity of standard merge sort is less, O(n Log n).

Approach 2: The idea: We start comparing elements that are far from each other 
rather than adjacent. Basically we are using shell sorting to merge two sorted 
arrays with O(1) extra space.

mergeSort(): 

Calculate mid two split the array in two halves(left sub-array and right sub-array)
Recursively call merge sort on left sub-array and right sub-array to sort them
Call merge function to merge left sub-array and right sub-array
merge():

For every pass, we calculate the gap and compare the elements towards the right of the gap.
Initiate the gap with ceiling value of n/2 where n is the combined length 
of left and right sub-array.

Every pass, the gap reduces to the ceiling value of gap/2.
Take a pointer i to pass the array.
Swap the ith and (i+gap)th elements if (i+gap)th element is smaller than
(or greater than when sorting in decreasing order) ith element.
Stop when (i+gap) reaches n.
Input: 10, 30, 14, 11, 16, 7, 28

Note: Assume left and right subarrays has been sorted so we are merging sorted 
subarrays [10, 14, 30] and [7, 11, 16, 28]

Start with

gap =  ceiling of n/2 = 7/2 = 4

[This gap is for whole merged array]

10, 14, 30, 7, 11, 16, 28

10, 14, 30, 7, 11, 16, 28

10, 14, 30, 7, 11, 16, 28

10, 14, 28, 7, 11, 16, 30

gap =  ceiling of 4/2 = 2

10, 14, 28, 7, 11, 16, 30

10, 14, 28, 7, 11, 16, 30

10, 7, 28, 14, 11, 16, 30

10, 7, 11, 14, 28, 16, 30

10, 7, 11, 14, 28, 16, 30

 

gap =  ceiling of 2/2 = 1

10, 7, 11, 14, 28, 16, 30

7, 10, 11, 14, 28, 16, 30

7, 10, 11, 14, 28, 16, 30

7, 10, 11, 14, 28, 16, 30

7, 10, 11, 14, 28, 16, 30

7, 10, 11, 14, 16, 28, 30

 

Output: 7, 10, 11, 14, 16, 28, 30

Below is the implementation of the above approach:

*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Calculating next gap
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
         
    return (int)ceil(gap / 2.0);
}
 
// Function for swapping
void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
 
// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void inPlaceMerge(int nums[], int start,
                              int end)
{
    int gap = end - start + 1;
     
    for(gap = nextGap(gap);
        gap > 0; gap = nextGap(gap))
    {
        for(int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (nums[i] > nums[j])
                swap(nums, i, j);
        }
    }
}
 
// merge sort makes log n recursive calls
// and each time calls merge()
// which takes nlog n steps
// Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
// 4((n/4)*log(n/4)) +.....+ 1)
// Time Complexity: O(logn*(n*log n))
// i.e. O(n*(logn)^2)
// Space Complexity: O(1)
void mergeSort(int nums[], int s, int e)
{
    if (s == e)
        return;
 
    // Calculating mid to slice the
    // array in two halves
    int mid = (s + e) / 2;
 
    // Recursive calls to sort left
    // and right subarrays
    mergeSort(nums, s, mid);
    mergeSort(nums, mid + 1, e);
     
    inPlaceMerge(nums, s, e);
}
 
// Driver Code
int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
     
    mergeSort(nums, 0, nums_size-1);
     
    for(int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
 
/*
Output
5 6 7 11 12 13 
Time Complexity: O(log n*nlog n)

Note: mergeSort method makes log n recursive calls and each time merge 
is called which takes n log n time to merge 2 sorted sub-arrays

Approach 3: Here we use the below technique:

Suppose we have a number A and we want to  
convert it to a number B and there is also a  
constraint that we can recover number A any  
time without using other variable.To achieve  
this we chose a number N which is greater  
than both numbers and add B*N in A.
so A --> A+B*N

To get number B out of (A+B*N)  
we divide (A+B*N) by N (A+B*N)/N = B.

To get number A out of (A+B*N)  
we take modulo with N (A+B*N)%N = A.

-> In short by taking modulo  
we get old number back and taking divide  
we new number.
mergeSort():

Calculate mid two split the array into two halves(left sub-array and right sub-array)
Recursively call merge sort on left sub-array and right sub-array to sort them
Call merge function to merge left sub-array and right sub-array
merge():

We first find the maximum element of both sub-array and increment it 
one to avoid collision of 0 and maximum element during modulo operation.
The idea is to traverse both sub-arrays from starting simultaneously. 
One starts from l till m and another starts from m+1 till r. So, We will 
initialize 3 pointers say i, j, k.

i will move from l till m; j will move from m+1 till r; k will move from l till r.
Now update value a[k] by adding min(a[i],a[j])*maximum_element.
Then also update those elements which are left in both sub-arrays.
After updating all the elements divide all the elements by maximum_element 
so we get the updated array back.
Below is the implementation of the above approach:
*/

// C++ program in-place Merge Sort
#include <bits/stdc++.h>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void mergeInPlace(int a[], int l, int m, int r)
{
    // increment the maximum_element by one to avoid
    // collision of 0 and maximum element of array in modulo
    // operation
    int mx = max(a[m], a[r]) + 1;
 
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r && k <= r) {
 
        // recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = a[j] % mx;
        if (e1 <= e2) {
            a[k] += (e1 * mx);
            i++;
            k++;
        }
        else {
            a[k] += (e2 * mx);
            j++;
            k++;
        }
    }
 
    // process those elements which are left in the array
    while (i <= m) {
        int el = a[i] % mx;
        a[k] += (el * mx);
        i++;
        k++;
    }
 
    while (j <= r) {
        int el = a[j] % mx;
        a[k] += (el * mx);
        j++;
        k++;
    }
 
    // finally update elements by dividing with maximum
    // element
    for (int i = l; i <= r; i++)
        a[i] /= mx;
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
 
        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeInPlace(arr, l, m, r);
    }
}
 
// Driver Code
int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
 
    mergeSort(nums, 0, nums_size - 1);
 
    for (int i = 0; i < nums_size; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
 
/*
Output
5 6 7 11 12 13 
Time Complexity: O(n log n)
Note:  Time Complexity of above approach is O(n2) because merge is O(n). 
Time complexity of standard merge sort is  O(n log n).

Approach 4: Here we use the following technique to perform an in-place merge

Given 2 adjacent sorted sub-arrays within an array (hereafter
named A and B for convenience), appreciate that we can swap
some of the last portion of A with an equal number of elements
from the start of B, such that after the exchange, all of the
elements in A are less than or equal to any element in B.

After this exchange, this leaves with the A containing 2 sorted
sub-arrays, being the first original portion of A, and the first
original portion of B, and sub-array B now containing 2 sorted
sub-arrays, being the final original portion of A followed by
the final original portion of B

We can now recursively call the merge operation with the 2
sub-arrays of A, followed by recursively calling the merge
operation with the 2 sub-arrays of B

We stop the recursion when either A or B are empty, or when
either sub-array is small enough to efficiently merge into
the other sub-array using insertion sort. 
The above procedure naturally lends itself to the following implementation 
of an in-place merge sort.

merge():

Hereafter, for convenience, we’ll refer to the first sub-array as A, 
and the second sub-array as B
If either A or B are empty, or if the first element B is not less than 
the last element of A then we’re done
If the length of A is small enough and if it’s length is less than the length 
of B, then use insertion sort to merge A into B and return
If the length of B is small enough then use insertion sort to merge B into A and return
Find the location in A where we can exchange the remaining portion of A with the 
first-portion of B, such that all the elements in A are less than or equal to any element in B
Perform the exchange between A and B
Recursively call merge() on the 2 sorted sub-arrays now residing in A
Recursively call merge() on the 2 sorted sub-arrays now residing in B
merge_sort():

Split the array into two halves(left sub-array and right sub-array)
Recursively call merge_sort() on left sub-array and right sub-array to sort them
Call merge function to merge left sub-array and right sub-array

*/

// Merge In Place in C++
 
#include <iostream>
using namespace std;
 
#define __INSERT_THRESH 5
#define __swap(x, y) (t = *(x), *(x) = *(y), *(y) = t)
 
// Both sorted sub-arrays must be adjacent in 'a'
// 'an' is the length of the first sorted section in 'a'
// 'bn' is the length of the second sorted section in 'a'
static void merge(int* a, size_t an, size_t bn)
{
    int *b = a + an, *e = b + bn, *s, t;
 
    // Return right now if we're done
    if (an == 0 || bn == 0 || !(*b < *(b - 1)))
        return;
 
    // Do insertion sort to merge if size of sub-arrays are
    // small enough
    if (an < __INSERT_THRESH && an <= bn) {
        for (int *p = b, *v; p > a;
             p--) // Insert Sort A into B
            for (v = p, s = p - 1; v < e && *v < *s;
                 s = v, v++)
                __swap(s, v);
        return;
    }
 
    if (bn < __INSERT_THRESH) {
        for (int *p = b, *v; p < e;
             p++) // Insert Sort B into A
            for (s = p, v = p - 1; s > a && *s < *v;
                 s = v, v--)
                __swap(s, v);
        return;
    }
 
    // Find the pivot points.  Basically this is just
    // finding the point in 'a' where we can swap in the
    // first part of 'b' such that after the swap the last
    // element in 'a' will be less than or equal to the
    // least element in 'b'
    int *pa = a, *pb = b;
 
    for (s = a; s < b && pb < e; s++)
        if (*pb < *pa)
            pb++;
        else
            pa++;
    pa += b - s;
 
    // Swap first part of b with last part of a
    for (int *la = pa, *fb = b; la < b; la++, fb++)
        __swap(la, fb);
 
    // Now merge the two sub-array pairings
    merge(a, pa - a, pb - b);
    merge(b, pb - b, e - pb);
} // merge_array_inplace
 
#undef __swap
#undef __INSERT_THRESH
 
// Merge Sort Implementation
void merge_sort(int* a, size_t n)
{
    size_t m = (n + 1) / 2;
 
    // Sort first and second halves
    if (m > 1)
        merge_sort(a, m);
 
    if (n - m > 1)
        merge_sort(a + m, n - m);
 
    // Now merge the two sorted sub-arrays together
    merge(a, m, n - m);
}
 
// Function to print an array
void print_array(int a[], size_t n)
{
    if (n > 0) {
        cout <<" "<< a[0];
        for (size_t i = 1; i < n; i++)
            cout <<" "<< a[i];
    }
    cout <<"\n";
}
 
// Driver program to test sort utility
int main()
{
    int a[] = { 3, 16, 5, 14, 8,  10, 7, 15,
                1, 13, 4, 9,  12, 11, 6, 2 };
    size_t n = sizeof(a) / sizeof(a[0]);
 
    merge_sort(a, n);
 
    print_array(a, n);
    return 0;
}
 
/*
Output
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Time Complexity of merge():  Worst Case: O(n^2),  Average: O(n log n),  Best: O(1)

Time Complexity of merge_sort() function:  Overall: O(log n) for the recursion alone, 
    due to always evenly dividing the array in 2

Time Complexity of merge_sort() overall:  Worst Case: O(n^2 log n),  
    Average: O(n (log n)^2), Best: O(log n)

The worst-case occurs when every sub-array exchange within merge() results 
    in just _INSERT_THRESH-1 elements being exchanged

*/