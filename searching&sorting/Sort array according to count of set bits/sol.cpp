/*
Sort array according to count of set bits

Given an array of integers, sort the array (in descending order) according to 
count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, 
sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
Example 2:
Input: 
arr[] = {1, 2, 3, 4, 5, 6};
Output: 
3 5 6 1 2 4
Explanation:
3  - 0011
5  - 0101
6  - 0110
1  - 0001
2  - 0010
4  - 0100
hence the non-increasing sorted order is
{3, 5, 6}, {1, 2, 4}


Your Task:
You don't need to print anything, printing is done by the driver code itself. 
You just need to complete the function sortBySetBitCount() which takes the 
array arr[] and its size N as inputs and sort the array arr[] inplace. 
Use of extra space is prohibited.
 

Expected Time Complexity: O(N.log(N))
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 106

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n){
        stable_sort(arr, arr+n, cmp);
    }
    static int cmp(int a, int b){
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);
        if(count1<=count2)return false;
        return true;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/*
stable_sort() is used to sort the elements in the range [first, last) 
in ascending order. It is like std::sort, but stable_sort() keeps the 
relative order of elements with equivalent values. It comes under the 
<algorithm> header file.

It is O(n*log^2(n)). 

If additional memory linearly proportional to length is not 
available. If its available then O(n*log(n)).

Syntax:

template< class RandomIterator>
void stable_sort( RandomIterator first, RandomIterator last );
or

template< class RandomIterator, class Compare>
void stable_sort( RandomIterator first, RandomIterator last, Compare comp );
Parameters:

first:  iterator pointing to the first element in the range.
last:  iterator pointing to the past last element in the range.
comp: predicate function that accepts two arguments and returns true if the 
 two arguments are in order and false otherwise.
 
 
Like sort(), stable_sort() takes a third parameter that is used to specify 
the order in which elements are to be sorted. We can pass “greater()” function 
to sort in decreasing order. This function does comparison in a way that puts 
greater element before. 

Syntax:

// arr is the array and n is the size
stable_sort(arr, arr + n, greater<int>());  

*/
