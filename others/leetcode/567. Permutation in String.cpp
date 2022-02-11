/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> map_s1(26), map_s2(26);
		for(char& i1 : s1) 
			map_s1[i1 - 'a']++;
		for(int i = 0; i < s2.size(); i++) {
			map_s2[s2[i] - 'a']++;
			if(i >= s1.size() - 1) {
				if(map_s2 == map_s1)  // Time: O(26)
					return true;
				map_s2[s2[i - s1.size() + 1] - 'a']--;
			}
		}
		return false;
	}
};
// Time complexity: O(n * 26) = O(n)
// Time space: O(26 * 2) = O(1)