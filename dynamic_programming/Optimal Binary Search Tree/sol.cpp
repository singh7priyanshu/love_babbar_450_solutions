/*
Optimal Binary Search Tree


for better explanation visit
https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/


Given a sorted array key [0.. n-1] of search keys and an 
array freq[0.. n-1] of frequency counts, where freq[i] is 
the number of searches for keys[i]. Construct a binary search 
tree of all keys such that the total cost of all the searches 
is as small as possible.

Let us first define the cost of a BST. The cost of a BST node 
is the level of that node multiplied by its frequency. 
The level of the root is 1.

Examples:  

Input:  keys[] = {10, 12}, freq[] = {34, 50}
There can be following two possible BSTs 
        10                       12
          \                     / 
           12                 10
          I                     II

Frequency of searches of 10 and 12 are 34 and 50 respectively.
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118 


Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
There can be following possible BSTs
    10                12                 20         10              20
      \             /    \              /             \            /
      12          10     20           12               20         10  
        \                            /                 /           \
         20                        10                12             12  
     I               II             III             IV             V

Among all possible BSTs, cost of the fifth BST is minimum.  
Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142 


1) Optimal Substructure: 
The optimal cost for freq[i..j] can be recursively calculated 
using the following formula. 

optcost(i, j) = summation of freq[k] over k = i to j  + 
    minimum of [optcost(i, r-1) + optcost(r+1, j)] over r = i to j.  

We need to calculate optCost(0, n-1) to find the result. 

The idea of above formula is simple, we one by one try all nodes 
as root (r varies from i to j in second term). 

When we make rth node as root, we recursively calculate optimal cost 
from i to r-1 and r+1 to j. 

We add sum of frequencies from i to j (see first term in the above formula)

The reason for adding the sum of frequencies from i to j:

This can be divided into 2 parts one is the freq[r]+sum of 
frequencies of all elements from i to j except r. 
The term freq[r] is added because it is going to be root 
and that means level of 1, so freq[r]*1=freq[r]. 

Now the actual part comes, we are adding the frequencies 
of remaining elements because as we take r as root then 
all the elements other than that are going 1 level down 
than that is calculated in the subproblem. 

Let me put it in a more clear way, for calculating optcost(i,j) 
we assume that the r is taken as root and calculate 
min of opt(i,r-1)+opt(r+1,j) for all i<=r<=j. 
Here for every subproblem we are  choosing one node as a root. 

But in reality the level of subproblem root and all its 
descendant nodes will be 1 greater than the level of the 
parent problem root. Therefore the frequency of all the nodes 
except r should be added which accounts to the descend in 
their level compared to level assumed in subproblem.

2) Overlapping Subproblems 
Following is recursive implementation that simply follows the 
recursive structure mentioned above. 
 

C++
*/
// A naive recursive implementation of
// optimal binary search tree problem
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j);
 
// A recursive function to calculate
// cost of optimal binary search tree
int optCost(int freq[], int i, int j)
{
    // Base cases
    if (j < i)  // no elements in this subarray
        return 0;
    if (j == i) // one element in this subarray
        return freq[i];
     
    // Get sum of freq[i], freq[i+1], ... freq[j]
    int fsum = sum(freq, i, j);
     
    // Initialize minimum value
    int min = INT_MAX;
     
    // One by one consider all elements
    // as root and recursively find cost
    // of the BST, compare the cost with
    // min and update min if needed
    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) +
                   optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }
     
    // Return minimum value
    return min + fsum;
}
 
// The main function that calculates
// minimum cost of a Binary Search Tree.
// It mainly uses optCost() to find
// the optimal cost.
int optimalSearchTree(int keys[],
                      int freq[], int n)
{
    // Here array keys[] is assumed to be
    // sorted in increasing order. If keys[]
    // is not sorted, then add code to sort
    // keys, and rearrange freq[] accordingly.
    return optCost(freq, 0, n - 1);
}
 
// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    s += freq[k];
    return s;
}
 
// Driver Code
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "
         << optimalSearchTree(keys, freq, n);
    return 0;
}
/*
Output: 

Cost of Optimal BST is 142
Time complexity of the above naive recursive 
approach is exponential. It should be noted that the above 
function computes the same subproblems again and again. 

We can see many subproblems being repeated in the following 
recursion tree for freq[1..4]. 
 



Since same subproblems are called again, this problem has 
Overlapping Subproblems property. So optimal BST problem 
has both properties (see this and this) of a dynamic programming problem. 

Like other typical Dynamic Programming(DP) problems, recomputations 
of same subproblems can be avoided by constructing a temporary array 
cost[][] in bottom up manner.

Dynamic Programming Solution 
Following is C/C++ implementation for optimal BST problem using 
Dynamic Programming. We use an auxiliary array cost[n][n] to store 
the solutions of subproblems. cost[0][n-1] will hold the final result. 

The challenge in implementation is, all diagonal values must be filled 
first, then the values which lie on the line just above the diagonal. 

In other words, we must first fill all cost[i][i] values, then all 
cost[i][i+1] values, then all cost[i][i+2] values. 

So how to fill the 2D array in such manner> The idea used 
in the implementation is same as Matrix Chain Multiplication problem, 

we use a variable ‘L’ for chain length and increment ‘L’, one by one. 

We calculate column number ‘j’ using the values of ‘i’ and ‘L’. 
 

C++
*/
// Dynamic Programming code for Optimal Binary Search
// Tree Problem
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j);
 
/* A Dynamic Programming based function that calculates
minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n)
{
    /* Create an auxiliary 2D matrix to store results
    of subproblems */
    int cost[n][n];
 
    /* cost[i][j] = Optimal cost of binary search tree
    that can be formed from keys[i] to keys[j].
    cost[0][n-1] will store the resultant cost */
 
    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
 
    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L = 2; L <= n; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= n-L+1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i+L-1;
            cost[i][j] = INT_MAX;
 
            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
            // c = cost when keys[r] becomes root of this subtree
            int c = ((r > i)? cost[i][r-1]:0) +
                    ((r < j)? cost[r+1][j]:0) +
                    sum(freq, i, j);
            if (c < cost[i][j])
                cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}
 
// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    s += freq[k];
    return s;
}
 
// Driver code
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
    return 0;
}
/*
Output: 
 

Cost of Optimal BST is 142
Notes 
1) The time complexity of the above solution is O(n^4). 
    The time complexity can be easily reduced to O(n^3) 
    by pre-calculating sum of frequencies instead of 
    calling sum() again and again.
2) In the above solutions, we have computed optimal cost only. 
    The solutions can be easily modified to store the structure 
    of BSTs also. We can create another auxiliary array of 
    size n to store the structure of tree. All we need to do is, 
    store the chosen ‘r’ in the innermost loop.

