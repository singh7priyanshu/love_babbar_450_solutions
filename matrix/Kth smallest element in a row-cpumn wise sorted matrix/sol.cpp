/*
Kth smallest element in a row-cpumn wise sorted matrix

Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes 
the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N


*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];

int kthSmallest(int mat[MAX][MAX], int n, int k);

// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a min heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k <= 0 || k > n*n)
       return INT_MAX;

    // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] =  {mat[0][i], 0, i};
    buildHeap(harr, n);

    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
       // Get current heap root
       hr = harr[0];

       // Get next value from column of root's value. If the
       // value stored at root was last value in its column,
       // then assign INFINITE as next value
       int nextval = (hr.r < (n-1))? mat[hr.r + 1][hr.c]: INT_MAX;

       // Update heap root with next value
       harr[0] =  {nextval, (hr.r) + 1, hr.c};

       // Heapify root
       minHeapify(harr, 0, n);
    }

    // Return the value at last extracted root
    return hr.val;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)cin>>mat[i][j];
        }
        int r;
        cin>>r;
        cout<<kthSmallest(mat, n, r)<<endl;
    }
    return 0;
}