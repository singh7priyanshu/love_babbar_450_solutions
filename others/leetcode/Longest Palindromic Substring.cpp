/*
Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

*/

        class Solution {
        public:
                string longestPalindrome(string s) {
                        int n = s.size();        
                        if(n<=1)
                                return s;

                        // table[i][j] represents whether string i to j is a palindrome or NOT
                        bool table[n][n];
                        memset(table,false,sizeof(table));
        
        
                        // Base condition => Single letter is always a palindrome
        
                        for(int i=0;i<n;i++)
                                table[i][i]=true;            
        
        
                        // ex. str => Asome_palindromeA
                        //              i................j
                        //  if str[i]==str[j] and string i+1 to j-1 is
                        //    pallindrome then str i to j is palindrome  
        
                        // if len of str is 2 then
                        // str[i+1]==[i] is condition for str to be pall...
                        // Example  str=> C.C 
                        //                i.i+1
        
        
                        int start =0;
                        int maxLen=1;
        
                        for(int i=0;i<n;i++){
                                if(s[i]==s[i+1]){
                                        start=i;
                                        maxLen=2;
                                        table[i][i+1]=true;
                                }
                        }
        
                        for(int k=3;k<=n;k++){
                                for(int i=0;i<n-k+1;i++){
                                        int j=i+k-1;
                                        if(s[i]==s[j] && table[i+1][j-1]==true){
                                                table[i][j]=true;
                                                start=i;
                                                if(maxLen<j-i+1)
                                                        maxLen=j-i+1;
                                        }
                                }
                        }
               
                        return s.substr(start,maxLen);
        
                }
        };
