/*
Permutation CoefficientProblem

Permutation refers to the process of arranging all the members 
of a given set to form a sequence. The number of permutations 
on a set of n elements is given by n! , where “!” represents factorial. 

The Permutation Coefficient represented by P(n, k) is used to 
represent the number of ways to obtain an ordered subset 
having k elements from a set of n elements.

Mathematically it’s given as: 

    |   P(n, k) = n . (n-1) . (n-2)......(n-k+1). |     ( k factors)
    which is 0 when k>n, and otherwise is equal to 
        (n!)/(n-k)!


Examples : 

P(10, 2) = 90
P(10, 3) = 720
P(10, 0) = 1
P(10, 1) = 10

The coefficient can also be computed recursively using the below 
recursive formula:  

P(n, k) = P(n-1, k) + k* P(n-1, k-1)  

If we observe closely, we can analyze that the problem has 
overlapping substructure, hence we can apply dynamic programming 
here. Below is a program implementing the same idea. 

*/

// A Dynamic Programming based
// solution that uses table P[][]
// to calculate the Permutation
// Coefficient
#include<bits/stdc++.h>
 
// Returns value of Permutation
// Coefficient P(n, k)
int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];
 
    // Calculate value of Permutation
    // Coefficient in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            // Base Cases
            if (j == 0)
                P[i][j] = 1;
 
            // Calculate value using
            // previously stored values
            else
                P[i][j] = P[i - 1][j] +
                        (j * P[i - 1][j - 1]);
 
            // This step is important
            // as P(i,j)=0 for j>i
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}
 
// Driver Code
int main()
{
    int n = 10, k = 2;
    printf("Value of P(%d, %d) is %d ",
            n, k, permutationCoeff(n, k));
    return 0;
}
/*
Output : 

Value of P(10, 2) is 90 
Here as we can see the time complexity is O(n*k) and space 
complexity is O(n*k) as the program uses an auxiliary matrix 
to store the result.

Can we do it in O(n) time ?
Let us suppose we maintain a single 1D array to compute the 
factorials up to n. We can use computed factorial value and 
apply the formula P(n, k) = n! / (n-k)!. Below is a program 
illustrating the same concept.


*/

// A O(n) solution that uses
// table fact[] to calculate
// the Permutation Coefficient
#include<bits/stdc++.h>
using namespace std;
 
// Returns value of Permutation
// Coefficient P(n, k)
int permutationCoeff(int n, int k)
{
    int fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}
 
// Driver Code
int main()
{
    int n = 10, k = 2;
     
    cout << "Value of P(" << n << ", "
        << k << ") is "
        << permutationCoeff(n, k);
 
    return 0;
}

/*
Output :

Value of P(10, 2) is 90 
A O(n) time and O(1) Extra Space Solution 
*/


// A O(n) time and O(1) extra
// space solution to calculate
// the Permutation Coefficient
#include <iostream>
using namespace std;
 
int PermutationCoeff(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}
 
// Driver Code
int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << ", " << k
         << ") is " << PermutationCoeff(n, k);
 
    return 0;
}

/*
Output : 

Value of P(10, 2) is 90 
*/