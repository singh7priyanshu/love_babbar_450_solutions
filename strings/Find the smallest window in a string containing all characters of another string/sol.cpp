/*
Find the smallest window in a string containing all characters of another string

Given two strings S and P. Find the smallest window in the string S consisting of all 
the characters(including duplicates) of the string P.  Return "-1" in case there is no 
such window present. In case there are multiple such windows of same length, return the 
one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function 
smallestWindow() which takes two string S and P as input paramters and returns the smallest 
window in string S having all the characters of the string P. In case there are multiple 
such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        //if length of string p is greater than string s then we return -1.
        if(p.length()>s.length())
        {
            return "-1";
        }
        else
        {
            //using hash tables to store the count of characters in strings.
            int shash[26]={0};
            int phash[26]={0};
            
            //storing the count of characters in string p in hash table.
            for(int i=0;i<p.length();i++)
            {
                phash[p[i]-'a']++;
            }
            int counter=0;
            int begin=0;
            int startindex=-1;
            int length=0;
            int minlength=INT_MAX;
            for(int i=0;i<s.length();i++)
            {
                //storing the count of characters in string s in hash table.
                shash[s[i]-'a']++;
                
                //if count of current character in string s is equal to or less 
                //than in string p, we increment the counter.
                if(phash[s[i]]-'a'!=0&&shash[s[i]-'a']<=phash[s[i]-'a'])
                {
                    counter++;
                }
                //if all the characters are matched
                if(counter==p.length())
                {
                    //we try to minimize the window.
                    while(shash[s[begin]-'a']>phash[s[begin]-'a']||phash[s[begin]-'a']==0)
                    {
                        if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                        begin++;
                    }
                    //updating window size.
                    length=i-begin+1;
                    if(length<minlength)
                    {
                        //if new minimum sub-string is found, we store value
                        //of its starting index for new found window.
                        startindex=begin;
                        minlength=length;
                    }
                    
                }
            }
            //returning the smallest window or -1 if no such window is present.
            if(startindex==-1)
                return "-1";
            else
                return s.substr(startindex,minlength);
        }
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        string pat; cin>>pat;
        Solution ob;
        cout<<ob.smallestWindow(s, pat)<<endl;
    }
    return 0;
}