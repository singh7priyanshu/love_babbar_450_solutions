/*
Substring with Concatenation of All Words

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
 

Constraints:

1 <= s.length <= 104
s consists of lower-case English letters.
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] consists of lower-case English letters.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find_sub_str(string s, vector<string>& words, int start, vector<int>& ans,unordered_map<string,int> count){
        int word_size = words[0].size();//each word size
        int times = words.size();//times that I should get a substr 
        int end_pos = start + times*word_size - 1;
        if(end_pos > s.size() )//if end pos > s.size() return
            return;
        
        unordered_map<string,int> record;//record the count of word we have used
        for(int i=start;i<=end_pos;){//from start to end_pos
            while(times){
                string sub_str = s.substr(i,word_size);//get substring
				
				// find if substring in words 
                auto it = find(words.begin(),words.end(),sub_str);
                if(it != words.end()){//true
                    record[sub_str]++;//record it and count it
                }else{//false return 
                    return;
                }
                i+=word_size;
                times--;
            }
        }
		
		//check if two unordered_map  is  same
        if(record == count) //true push_back the start index to ans
            ans.push_back(start);
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int word_size = words[0].size(); //each word size
        int times = words.size(); //times that I should get a substr 
		
		// we should calculate the times of each word (in words) 
		// this unordered_map will be used in the function 
        unordered_map<string,int> count;
        for(auto w:words)
            count[w] += 1;
		
		/*
		 At the begining, I use the same way in the above function to find corrected substring
		 (use word size to get substring and let start_pos += word size )
		 but it will get WA
		 
		 ex: s = "fofoobar" words=["foo","bar"]
		
		- WA solution,  word size = 3
		 start_pos = 0 , substr = "fof" (not match in words)
		 start_pos = 0 + 3 = 3,  substr = "oob"
		 
		 but it will miss the correct answer
		 start_pos = 2 , substr = "foo"
		 -> get answer 2
		 
		 -Correct Soltuion
		 each char in s should get a substr
		 then we won't miss any substr
		*/
        for(int i=0;i<s.size();i++){    
            string sub_str = s.substr(i,word_size);
  
            auto it = find(words.begin(),words.end(),sub_str);
            if(it != words.end()){//if substr in words
                find_sub_str(s, words, i,ans,count); //do the function
            }
        }     
        return ans;
    }
};