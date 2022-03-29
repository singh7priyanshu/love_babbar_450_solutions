/*
Greedy Algorithm to find Minimum number of Coins

You are given a string s of lower case english alphabets. 
You can choose any two characters in the string and replace 
all the occurences of the first character with the second 
character and replace all the occurences of the second 
character with the first character. Your aim is to find 
the lexicographically smallest string that can be obtained 
by doing this operation at most once.

Example 1:

Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose a and c and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 
 

Example 2:

Input:
A = "abba"
Output: "abba"
Explanation:
In abba, we can get baab after doing the 
replacement operation once for a and b 
but that is not lexicographically smaller 
than abba. So, the answer is abba. 

Your Task:  
You don't need to read input or print anything. Your task 
is to complete the function chooseandswap() which takes the 
string A as input parameters and returns the lexicographically 
smallest string that is possible after doing the operation 
at most once.

Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)

 

Constraints:
1<= |A| <=105
*/

#include<bits/stdc++.h>
using namespace std;

int left_most[26];
class Solution{
public:
    string chooseandswap(string a){
        int n = a.size();
        string ans = "";
		for(int i = 0; i<=25; i++)left_most[i] = -1;
		for(int i = 0; i<=n-1; i++){
			if(left_most[a[i]-97]==-1)left_most[a[i]-97] = i;
		}
		int j = -1, mark = -1;
		for(int i = 0; i<=n-2; i++){
	        	j = i;
				for(int k = 0; k<=25; k++){
					if(left_most[k] > left_most[a[j]-97] && k < (int)(a[j]-97)){
						mark = k;
						break;
					}
				}
			if(mark!=-1)
			break;
		}
		if(mark!=-1){	
			for(int i = 0; i<=n-1; i++){
				if(a[i]==(char)(mark+97))ans += a[j];
				else if(a[i]==a[j])ans += ((char)(mark+97));
    			else ans += a[i];
			}
		}
		else{
			for(int i = 0; i<=n-1; i++)ans += a[i];
		}
		return ans;
    }
    
};

int main(){
    Solution ob;
    int t; cin>>t;
    while(t--){
         string a; cin>>a;
         cout<<ob.chooseandswap(a)<<endl;   
    }
    return 0;
}