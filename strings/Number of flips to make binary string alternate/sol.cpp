/*
Number of flips to make binary string alternate

Given a binary string, that is it contains only 0s and 1s. We need to make this string 
a sequence of alternate characters by flipping some of the bits, our goal is to minimize 
the number of bits to be flipped.

Example 1:

Input:
S = "001"
Output: 1
Explanation: 
We can flip the 0th bit to 1 to have
101.


Example 2:

Input:
S = "0001010111" 
Output: 2
Explanation: We can flip the 1st and 8th bit 
bit to have "0101010101"
101.

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
minFlips() which takes the string S as input and returns the minimum number of flips required.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105

*/

#include<bits/stdc++.h>
using namespace std;
    
int minFlips(string s);
int32_t main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        cout<<minFlips(s)<<endl;    
    }
}

int minFlips (string S){
    int ans1 = 0;
    for(int i = 0;i<S.length();i++){
        if((i%2 == 0 && S[i] == '1') || (i%2 == 1 && S[i] == '0'))ans1++;
    }
    int ans2 = 0;
    for(int i = 0;i<S.length();i++){
        if((i%2 == 1 && S[i] == '1') || (i%2 == 0 && S[i] == '0'))ans2++;
    }
    return min(ans1, ans2);
}
