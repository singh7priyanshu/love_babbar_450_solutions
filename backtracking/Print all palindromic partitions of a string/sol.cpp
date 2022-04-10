/*
Print all palindromic partitions of a string

Given a string, find all possible palindromic partitions of given string.
Example: 
 
 Input : nitin
 Output : n i t i n
          n iti n
          nitin

Input : geeks
Output : g e e k s
         g ee k s

Note that this problem is different from Palindrome Partitioning Problem, 
there the task was to find the partitioning with minimum cuts in input string. 

Here we need to print all possible partitions.
The idea is to go through every substring starting from first character, 
check if it is palindrome. If yes, then add the substring to solution 
and recur for remaining part. Below is complete algorithm.
Below is the implementation of above idea.

*/

// C++ program to print all palindromic partitions of a given string
#include<bits/stdc++.h>
using namespace std;

// A utility function to check if str is palindrome
bool isPalindrome(string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

// Recursive function to find all palindromic partitions of str[start..n-1]
// allPart --> A vector of vector of strings. Every vector inside it stores
//			 a partition
// currPart --> A vector of strings to store current partition
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,
				int start, int n, string str)
{
	// If 'start' has reached len
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for (int i=start; i<n; i++)
	{
		// If substring str[start..i] is palindrome
		if (isPalindrome(str, start, i))
		{
			// Add the substring to result
			currPart.push_back(str.substr(start, i-start+1));

			// Recur for remaining substring
			allPalPartUtil(allPart, currPart, i+1, n, str);
			
			// Remove substring str[start..i] from current
			// partition
			currPart.pop_back();
		}
	}
}

// Function to print all possible palindromic partitions of
// str. It mainly creates vectors and calls allPalPartUtil()
void allPalPartitions(string str)
{
	int n = str.length();

	// To Store all palindromic partitions
	vector<vector<string> > allPart;

	// To store current palindromic partition
	vector<string> currPart;

	// Call recursive function to generate all partitions
	// and store in allPart
	allPalPartUtil(allPart, currPart, 0, n, str);

	// Print all partitions generated by above call
	for (int i=0; i< allPart.size(); i++ )
	{
		for (int j=0; j<allPart[i].size(); j++)
			cout << allPart[i][j] << " ";
		cout << "\n";
	}
}

// Driver program
int main()
{
	string str = "nitin";
	allPalPartitions(str);
	return 0;
}

/*
Output
n i t i n 
n iti n 
nitin 
Approach 2: Expand around every palindrome

The idea is to split the string into all palindromes of length 1 
that is convert the string to a list of its characters 
(but as string data type) and then expand the smaller 
palindromes to bigger palindromes by checking if its left 
and right (reversed) are equal or not if they are equal then 
merge them and solve for new list recursively. 

Also if two adjacent strings of this list are equal 
(when one of them is reversed), merging them would also give a
palindrome so merge them and solve recursively.

*/

class GFG:
	def solve(self, arr):
		self.res.add(tuple(arr)) # add current partitioning to result
		if len(arr)<=1: # Base case when there is nothing to merge
			return
		for i in range(1,len(arr)):
			if arr[i-1]==arr[i][::-1]: # When two adjacent such that one is reverse of another
				brr = arr[:i-1] + [arr[i-1]+arr[i]] + arr[i+1:]
				self.solve(brr)
			if i+1<len(arr) and arr[i-1]==arr[i+1][::-1]: # All are individually palindrome,
			# when one left and one right of i are reverse of each other then we can merge
			# the three of them to form a new partitioning way
				brr = arr[:i-1] + [arr[i-1]+arr[i]+arr[i+1]] + arr[i+2:]
				self.solve(brr)
	def getGray(self, S):
		self.res = set() # result is a set of tuples to avoid same partition multiple times
		self.solve(list(S)) # Call recursive function to solve for S
		return sorted(list(self.res))
# Driver Code
if __name__ == '__main__':
	ob = GFG()
	allPart = ob.getGray("geeks")
	for i in range(len(allPart)):
		for j in range(len(allPart[i])):
			print(allPart[i][j], end = " ")
		print()


/*
Output
g e e k s 
g ee k s 
*/

