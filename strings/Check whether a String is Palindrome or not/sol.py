"""
Given a string S, check if it is palindrome or not.
Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
"""
class Solution:
    def isPalindrome(self, S):
	    if len(S)==1:
	        return 1
	    for i in range(0, int(len(S)/2)):
         	if S[i] != S[len(S)-i-1]:
                return 0
    	return 1
 
if __name__ == '__main__':
	T = int(input())
	for i in range(T):
		S = input()
		ob = Solution()
		answer = ob.isPalindrome(S)
		print(answer)