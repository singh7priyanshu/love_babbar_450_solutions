/*
664. Strange Printer 


Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.

*/

    class Solution {
    public:
        int strangePrinter(string s) {
            if (s.length() == 0) return 0;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), s.length()));
        for (int i = 0; i < s.length(); ++i) dp[i][i] = 1;
        for (int j = 0; j < s.length(); ++j) {
          for (int i = j; i >= 0; --i) {
            for (int k = i; k < j; ++k) {
              int tmp = dp[i][k] + dp[k + 1][j];
              if (s[k] == s[j]) --tmp;
              dp[i][j] = min(dp[i][j], tmp);
            }
          }
        }

        return dp[0][s.length() - 1];
        }
    };