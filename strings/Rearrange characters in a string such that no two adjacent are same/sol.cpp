/*
Rearrange characters in a string such that no two adjacent are same

Given a String S with repeated characters (only lowercase). The task is to rearrange characters in a 
string such that no two adjacent character are same.

Note: It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains 
any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example: 
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1:
All the repeated characters of the given string can be rearranged so that no adjacent charactes in the 
string is equal.
Testcase 3:
Repeated characters in the string cannot be rearranged such that there should not be any adjacent 
repeated character.

*/

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

class Solution{
    public:
    struct Key{
        int freq;
        char ch;
        bool operator<(const Key &k) const{
            return freq < k.freq;
        }
    };
    
    string rearrangeString(string str){
        int n = str.length();
        int count[MAX_CHAR] = {0};
        for(int i = 0;i<n;i++)count[str[i]-'a']++;
        priority_queue<Key>pq;
        for(char c = 'a' ; c<='z';c++){
            if(count[c-'a'])pq.push(Key{count[c-'a'], c});
        }
        str = "";
        Key prev {-1, '#'};
        while(!pq.empty()){
            Key k = pq.top();
            pq.pop();
            str = str + k.ch;
            if(prev.freq>0)pq.push(prev);
            (k.freq)--;
            prev = k;
        }
        if(n != str.length())return "-1";
        else return str;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for(int i = 0;i<str.length();i++)c[str[i]-'a']+=1;
        int f = 0;
        int x = (str.length()+1)/2;
        for(int i = 0;i<26;i++){
            if(c[i]>x)f=1;
        }
        if(f){
            if(str1=="-1")cout<<0<<endl;
            else cout<<1<<endl;
        }
        else{
            int a[26] = {0};
            int b[26] = {0};
            for(int i = 0;i<str.length();i++)a[str[i]-'a']+=1;
            for(int i = 0;i<str1.length();i++)b[str1[i]-'a']+=1;
            for(int i = 0;i<26;i++){
                if(a[i]!=b[i])flag = 0;
            }
            for(int i = 0;i<str1.length();i++){
                if(i>0){
                    if(str1[i-1]==str1[i])flag = 0;
                }
            }
            if(flag == 1)cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}