/*
Split the Binary string into two substring with equal 0’s and 1’s

Given a binary string str of length N, the task is to find the maximum count of 
consecutive substrings str can be divided into such that all the substrings are 
balanced i.e. they have equal number of 0s and 1s. If it is not possible to split 
str satisfying the conditions then print -1.

Example: 
 

Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010” 
Output: 3 

Input: str = “0000000000” 

Output: -1

Approach: Initialize count = 0 and traverse the string character by character and 
keep track of the number of 0s and 1s so far, whenever the count of 0s and 1s become 
equal increment the count. As in the given question, if it is not possible to split 
string then on that time count of 0s must not be equal to count of 1s then return -1 
else print the value of count after the traversal of the complete string.

Below is the implementation of the above approach:

*/

// C++ implementation of the approach

//Time complexity: O(N) where N is the length of string 
//Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{

	// To store the count of 0s and 1s
	int count0 = 0, count1 = 0;

	// To store the count of maximum
	// substrings str can be divided into
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			count0++;
		}
		else {
			count1++;
		}
		if (count0 == count1) {
			cnt++;
		}
	}

	// It is not possible to
	// split the string
	if (count0!=count1) {
		return -1;
	}

	return cnt;
}

// Driver code
int main()
{
	string str = "0100110101";
	int n = str.length();

	cout << maxSubStr(str, n);

	return 0;
}

/*
Output: 
4
*/
