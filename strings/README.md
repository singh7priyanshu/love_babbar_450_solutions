# lovebabbarreadingmaterial
## Strings
### Write a function that reverses a string. The input string is given as an array of characters s.
##### cpp
        class Solution {
                public:
                void reverseString(vector<char>& s) {
                        int i = 0;
                        int j = s.size()-1;
                        while (i < j) {
	                        if(s[i] == s[j]){
                                        i++;
                                        j--;
                                        continue;
                                }
	                        char tmp = s[i];
		                s[i] = s[j];
		                s[j] = tmp;
	       
	                        i++;
	                        j--;
                        }
        
                }
        };
        
##### python
        class Solution:
                def reverseString(self, s: List[str]) -> None:
                        s.reverse();
 

### Palindrome String
#### Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome

##### cpp 
	#include<bits/stdc++.h>
	using namespace std;

	class Solution{
	public:	
	
		int isPalindrome(string S){
	    		// Your code goes here
	    		for(int i = 0; i < S.size()/2; i++)
				if(S[i] != S[S.size() - i - 1])
					return 0;

			return 1;
		}
	};

	int main(){
    		ios_base::sync_with_stdio(0);
    		cin.tie(NULL);
    		cout.tie(NULL);

    		int t;
    		cin>>t;
    		while(t--){
        		string s;
        		cin>>s;
        		Solution ob;
        		cout<<ob.isPalindrome(s)<<"\n";
    		}
    		return 0;
	}
	
##### python

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
