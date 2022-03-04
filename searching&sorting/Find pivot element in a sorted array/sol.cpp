/*
Find pivot element in a sorted array

Problem Statement – Suppose we have a sorted array, and now we rotate it N times, 
find the pivot element. The pivot element would be the largest element. 

Clues –

Solution should be O(log N) in time and O(1) in space.
Can you think of  a binary search based solution where you keep comparing the 
middle element with the last element?

Solution – The pivot element is basically, the largest element in an array. 
For a sorted and rotated array, it might be somewhere in between. 
We can solve this in O(log N) time, through a divide-and-conquer 
approach, which is similar to peak finding algorithm. We will have 
the lower limit (low) and the upper limit (high) from which we will 
calculate the ‘mid’. Now, we must address a few cases –
arr[mid] > arr[high] – If the mid element is greater than the last element, 
    then the pivot should be in the second half of the array. Why is this so? 
    This is actually because it is a sorted and rotated array. 
    You may not understand this at first, but think of the values 
    of the elements in the array as a histogram.

arr[mid] < arr[high] – If the mid element is less than the last element, 
    then the pivot should be in the first half of the range.

If mid element is a peak – If the mid element satisfies the property of the 
    peak element (not lesser than its neighbors), then, it is the pivot.

If we can put these conditions, and handle the trivial cases, we can compute the 
pivot element. The number of times the array is rotated would 
be (IndexOfPivotReturned + 1).

Code –
*/

// A Divide-and-Conquer approach to find the pivot (highest) element in
// a sorted rotated array - returns the index of the pivot -> O(log N)
int peakElement(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;
     
    if (mid == lowerBound) {
        if (mid == upperBound) {
            // Only 1 element
            return mid;
        } else if (arr[mid] >= arr[mid + 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else if (mid == upperBound) {
        if (arr[mid] >= arr[mid - 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            // Mid value is the pivot
            return mid;
        } else if (arr[mid] > arr[high]) {
            // The Pivot is in the second half
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        } else if (arr[mid] < arr[high]) {
            // The Pivot is in the first half
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
        }
    }
     
    return -1;
}

