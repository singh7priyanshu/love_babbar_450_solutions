/*
Find Maximum number possible by doing at-most K swaps

Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.


Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void match(string& str, string& res){
        for(int i=0; i<str.size(); i++){
            if( res[i] > str[i] )return;
            if( res[i] < str[i] ){
                res = str;
                return;
            }
        }
    }
    public:
    void setDigit(string& str, int index, string& res, int k){
        if(k==0 || index==str.size()-1){
            match(str,res);
            return;
        }
        int maxDigit = 0;
        for(int i=index; i<str.size(); i++)
            maxDigit = max( maxDigit, str[i]-'0' );
        if( str[index]-'0' == maxDigit ){
            setDigit(str, index+1, res, k);
            return;
        }
        for(int i=index+1; i<str.size(); i++){
            if( str[i]-'0' == maxDigit ){
                swap( str[index] , str[i] );
                setDigit(str, index+1, res, k-1);
                swap( str[index] , str[i] );
            }
        }
    }

    public:
    string findMaximumNum(string str, int k){
        string res = str;
        setDigit(str, 0, res, k);
        return res;
    }

};

int main(){
    int t, k;
    string str;
    cin>>t;
    while(t--){
        cin>>k>>str;
        Solution ob;
        cout<<ob.findMaximumNum(str, k)<<endl;
    }
    return 0;
}