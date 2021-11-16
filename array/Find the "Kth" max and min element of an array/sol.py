#Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth 
#smallest element in the given array. It is given that all array elements are distinct.
def kth_min_max(A, k):
   		A = sorted(A)
   		kth_min = A[k-1]  # k-th element from the beginning of sorted array
   		kth_max = A[-k]  # k-th element from the end of sorted array
   		return (kth_min, kth_max)
# kth_min_max([-1, 10, -5, 30, -8, 40, 60], 3) --> (-1, 30)