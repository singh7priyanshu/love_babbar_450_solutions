/*
Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dividend_long = labs(dividend), divisor_long = labs(divisor), res = 0;
        /*
        The labs() function in C++ returns the absolute value of a long or long int data.
        The labs() function can be thought as the long int version of abs(). 
        It is defined in <cstdlib> header file.
        */
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        while (dividend_long >= divisor_long) {
            long step = 1;
            long tmp = divisor_long;
            while (dividend_long >= tmp) {
                res += step;
                dividend_long -= tmp;
                step <<= 1;
                tmp <<= 1;
            }
        }
        res *= sign;
        return res > INT_MAX ? INT_MAX : res;
    }
};