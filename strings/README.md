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
 
 
