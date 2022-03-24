/*
Mobile Numeric Keypad Problem [ IMP ]

Given the mobile numeric keypad. You can only press buttons that are 
    up, left, right, or down to the current button. 
    
    You are not allowed to press bottom row corner buttons 
    (i.e. * and # ). Given a number N, the task is to find out 
    the number of possible numbers of the given length.

Example 1:

Input: 1
Output: 10
Explanation: Number of possible numbers 
would be 10 (0, 1, 2, 3, …., 9)  
Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11,
12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers 
will be 00, 08 (count: 2)
If we start with 1, valid numbers 
will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers 
will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers 
will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers 
will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers 
will be 55,54,52,56,58 (count: 5) 
and so on..

Your Task:  
You don't need to read input or print anything. Complete the function 
getCount() which takes N as input parameter and returns the integer value

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 25

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	long long getCount(int N){
		char keypad[4][3] = {{'1', '2', '3'},
		                     {'4', '5', '6'},
		                     {'7', '8', '9'},
		                     {'*', '0', '#'}};
		return getCountUtil(keypad, N);
	}
	
	long long getCountUtil(char keypad[][3], int n){
	    if(keypad == NULL || n <= 0)return 0;
	    if(n==1)return 10;
	    int row[] = {0, 0, -1, 0, 1};
	    int col[] = {0, -1, 0, 1, 0};
	    long long count[10][n+1];
	    int i = 0, j = 0, k = 0, move = 0, ro = 0, co = 0, num = 0;
	    long long nextNum = 0, totalCount = 0;
	    for(i = 0;i<=9;i++){
	        count[i][0] = 0;
	        count[i][1] = 1;
	    }
	    for(k = 2; k<=n;k++){
	        for(i = 0;i<4;i++){
	            for(j = 0;j<3;j++){
	                if(keypad[i][j] != '*' && keypad[i][j] != '#'){
	                    num = keypad[i][j]-'0';
	                    count[num][k] = 0;
	                    for(move = 0;move<5;move++){
	                        ro = i+row[move];
	                        co = j+col[move];
	                        if(ro>=0 && ro<=3 && co>=0 && co<=2 && keypad[ro][co] != '*' && keypad[ro][co] != '#'){
	                            nextNum = keypad[ro][co]-'0';
	                            count[num][k]+=count[nextNum][k-1];
	                        }
	                    }
	                }
	            }
	        }
	    }
	    totalCount = 0;
	    for(i = 0;i<=9;i++)totalCount += count[i][n];
	    return totalCount;
	}
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.getCount(n)<<endl;
    }
    return 0;
}