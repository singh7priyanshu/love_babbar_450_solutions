/*
Program for nth Catalan Number

Catalan numbers are a sequence of natural numbers that occurs 
in many interesting counting problems like following.

1. Count the number of expressions containing n pairs of 
    parentheses which are correctly matched. For n = 3, 
    possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2. Count the number of possible Binary Search Trees with n keys 

3. Count the number of full binary trees (A rooted binary tree is 
    full if every vertex has either two children or no children) 
    with n+1 leaves.

4. Given a number n, return the number of ways you can draw n chords 
    in a circle with 2 x n points such that no 2 chords intersect.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  

Recursive Solution 
Catalan numbers satisfy the following recursive formula. 

C(0) = 1 & C(n+1) = summatation of C(i)*C(n-i) for n >= 0
            from i = 0 to i = n.

Following is the implementation of above recursive formula.  

*/

#include <iostream>
using namespace std;

// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n)
{
	// Base case
	if (n <= 1)
		return 1;

	// catalan(n) is sum of
	// catalan(i)*catalan(n-i-1)
	unsigned long int res = 0;
	for (int i = 0; i < n; i++)
		res += catalan(i)
			* catalan(n - i - 1);

	return res;
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}


/*
Output
1 1 2 5 14 42 132 429 1430 4862 

Time complexity of above implementation is equivalent to 
nth catalan number. 

T(n) = summation of T(i)*T(n-i-1) for n>=1  
        from i = 0 to i = n-1.

The value of nth catalan number is exponential that makes 
the time complexity exponential.

Dynamic Programming Solution : We can observe that the above 
recursive implementation does a lot of repeated work (we can the 
same by drawing recursion tree). Since there are overlapping 
subproblems, we can use dynamic programming for this. 

Following is a Dynamic programming based implementation .

*/

#include <iostream>
using namespace std;

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n + 1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j] * catalan[i - j - 1];
	}

	// Return last entry
	return catalan[n];
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalanDP(i) << " ";
	return 0;
}

/*
Output
1 1 2 5 14 42 132 429 1430 4862 
Time Complexity: Time complexity of above implementation is O(n2)

Using Binomial Coefficient 
We can also use the below formula to find nth Catalan number in O(n) time. 

C(n) = 1  [ 2n ]
      --- [    ]
      n+1 [ n  ]

We have discussed a O(n) approach to find binomial coefficient nCr. 

*/

// C++ program for nth Catalan Number
#include <iostream>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
								unsigned int k)
{
	unsigned long int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate value of [n*(n-1)*---*(n-k+1)] /
	// [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n)
{
	// Calculate value of 2nCn
	unsigned long int c = binomialCoeff(2 * n, n);

	// return 2nCn/(n+1)
	return c / (n + 1);
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}

/*
Output
1 1 2 5 14 42 132 429 1430 4862 
Time Complexity: Time complexity of above implementation is O(n).
We can also use below formula to find nth catalan number in O(n) time. 

C(n) = (2n)! / (n+1)! n!


Use multi-precision library:  In this method, we have used boost 
multi-precision library, and the motive behind its use is just only 
to have precision meanwhile finding the large CATALAN’s number 
and a generalized technique using for loop to calculate Catalan numbers .  

For example: N = 5

Initially set cat_=1 then, print cat_  ,

then, iterate from i = 1 to i < 5

for i = 1; cat_ = cat_ * (4*1-2)=1*2=2
cat_ = cat_ / (i+1)=2/2 = 1      

For i = 2; cat_ = cat_ * (4*2-2)=1*6=6
cat_ = cat_ / (i+1)=6/3=2  

For i = 3 :-      cat_ = cat_ * (4*3-2)=2*10=20
cat_ = cat_ / (i+1)=20/4=5   

For i = 4 :-      cat_ = cat_ * (4*4-2)=5*14=70
 cat_ = cat_ / (i+1)=70/5=14     

Pseudocode: 

a) initially set cat_=1 and print it
b) run a for loop i=1 to i<=n
            cat_ *= (4*i-2)
            cat_ /= (i+1)
            print cat_
c) end loop and exit        


*/

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
 
// Function to print the number
void catalan(int n)
{
    cpp_int cat_ = 1;
 
    // For the first number
    cout << cat_ << " "; // C(0)
 
    // Iterate till N
    for (cpp_int i = 1; i <=n; i++)
    {
        // Calculate the number
        // and print it
        cat_ *= (4 * i - 2);
        cat_ /= (i + 1);
        cout << cat_ << " ";
    }
}
 
// Driver code
int main()
{
    int n = 5;
 
    // Function call
    catalan(n);
    return 0;
}

/*
Output
1 1 2 5 14 
Time Complexity: O(n)
Auxiliary Space: O(1)

Another solution using BigInteger in java:

Finding values of catalan numbers for N>80 is not possible 
even by using long in java, so we use BigInteger

Here we find solution using Binomial Coefficient method as 
discussed above

*/


import java.io.*;
import java.util.*;
import java.math.*;
 
class GFG
{
    public static BigInteger findCatalan(int n)
    {
        // using BigInteger to calculate large factorials
        BigInteger b = new BigInteger("1");
 
        // calculating n!
        for (int i = 1; i <= n; i++) {
            b = b.multiply(BigInteger.valueOf(i));
        }
 
        // calculating n! * n!
        b = b.multiply(b);
 
        BigInteger d = new BigInteger("1");
 
        // calculating (2n)!
        for (int i = 1; i <= 2 * n; i++) {
            d = d.multiply(BigInteger.valueOf(i));
        }
 
        // calculating (2n)! / (n! * n!)
        BigInteger ans = d.divide(b);
 
        // calculating (2n)! / ((n! * n!) * (n+1))
        ans = ans.divide(BigInteger.valueOf(n + 1));
        return ans;
    }
   
    // Driver Code
    public static void main(String[] args)
    {
        int n = 5;
        System.out.println(findCatalan(n));
    }
}


/*
Output
42

*/