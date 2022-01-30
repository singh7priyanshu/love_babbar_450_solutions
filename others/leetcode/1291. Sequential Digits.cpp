/*
1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9

*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int num = 0;
        for(int i = 1; i<10 ; i++)
        {
            num = i;
            for(int j = i+1;j<10;j++)
            {
                num = num*10 + j;
                if(num >= low && num <= high)
                {
                    result.push_back(num);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};