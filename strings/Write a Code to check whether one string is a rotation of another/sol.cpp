/*
Write a Code to check whether one string is a rotation of another

Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

Algorithm: areRotations(str1, str2)

    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.


*/

// C++ program to check if two given strings
// are rotations of each other
# include <bits/stdc++.h>
using namespace std;

/* Function checks if passed strings (str1
and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
/* Check if sizes of two strings are same */
if (str1.length() != str2.length())
		return false;

string temp = str1 + str1;
return (temp.find(str2) != string::npos);
}

/* Driver program to test areRotations */
int main()
{
string str1 = "AACD", str2 = "ACDA";
if (areRotations(str1, str2))
	printf("Strings are rotations of each other");
else
	printf("Strings are not rotations of each other");
return 0;
}


/*
Strings are rotations of each other
Method 2(Using STL):

Algorithm :

1. If the size of both the strings is not equal, then it can never be possible.

2. Push the original string into a queue q1.

3. Push the string to be checked inside another queue q2.

 4. Keep popping q2‘s and pushing it back into it till the number of such operations are less 
 than the size of the string.

5. If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.

*/

#include <bits/stdc++.h>
using namespace std;
bool check_rotation(string s, string goal)
{
	if (s.size() != goal.size())
		;
	queue<char> q1;
	for (int i = 0; i < s.size(); i++) {
		q1.push(s[i]);
	}
	queue<char> q2;
	for (int i = 0; i < goal.size(); i++) {
		q2.push(goal[i]);
	}
	int k = goal.size();
	while (k--) {
		char ch = q2.front();
		q2.pop();
		q2.push(ch);
		if (q2 == q1)
			return true;
	}
	return false;
}
int main()
{
	string s1 = "ABCD";
	string s2 = "CDAB";
	if (check_rotation(s1, s2))
		cout << s2 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s2 << " is not a rotated form of " << s1
			<< endl;
	string s3 = "ACBD";
	if (check_rotation(s1, s3))
		cout << s3 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s3 << " is not a rotated form of " << s1
			<< endl;
	return 0;
}


/*

CDAB is a rotated form of ABCD
ACBD is not a rotated form of ABCD
Library Functions Used: 
strstr: 
strstr finds a sub-string within a string. 
Prototype: char * strstr(const char *s1, const char *s2); 
See http://www.lix.polytechnique.fr/Labo/Leo.Liberti/public/computing/prog/c/C/MAN/strstr.htm for 
more details
strcat: 
strncat concatenate two strings 
Prototype: char *strcat(char *dest, const char *src); 
See http://www.lix.polytechnique.fr/Labo/Leo.Liberti/public/computing/prog/c/C/MAN/strcat.htm for 
more details

Time Complexity: Time complexity of this problem depends on the implementation of strstr function. 

If the implementation of strstr is done using KMP matcher then complexity of the above program is 
(-)(n1 + n2) where n1 and n2 are lengths of strings. KMP matcher takes (-)(n) time to find a substring
 in a string of length n where length of substring is assumed to be smaller than the string. 

Method 3:

Algorithm:

1.Find all the positions of first character of original string in the string to be checked.

2.For every position found, consider it to be the starting index of the string to be checked.

3.Beginning from the new starting index, compare both strings and check whether they are equal or not.

(Suppose original string to be s1,string to be checked be s2,n is length of strings and j is the 
position of first character of s1 in s2,

     then for i < (length of original string) ,check if s1[i]==s2[(j+1)%n). Return false if any 
     character mismatch is found, else return true.

4.Repeat 3rd step for all positions found.

*/


#include <iostream>
#include <vector>
using namespace std;

bool checkString(string &s1, string &s2, int indexFound, int Size)
{
	for(int i=0;i<Size;i++){
	//check whether the character is equal or not
		if(s1[i]!=s2[(indexFound+i)%Size])return false;
	// %Size keeps (indexFound+i) in bounds, since it ensures it's value is always less than Size
	}

	return true;
}

int main() {
	
string s1="abcd";
string s2="cdab";

if(s1.length()!=s2.length()){
	cout<<"s2 is not a rotation on s1"<<endl;
}
else{
	
	vector<int> indexes; //store occurences of the first character of s1
	
	int Size = s1.length();
	
	char firstChar = s1[0];
	
	
	for(int i=0;i<Size;i++)
	{
		if(s2[i]==firstChar)
		{
			indexes.push_back(i);
		}
	}
	

	bool isRotation=false;

	// check if the strings are rotation of each other for every occurence of firstChar in s2
	for(int idx: indexes)
	{
		isRotation = checkString( s1, s2, idx, Size);

		if(isRotation)
			break;
	}

	if(isRotation)cout<<"s2 is rotation of s1"<<endl;
	else cout<<"s2 is not a rotation of s1"<<endl;
	
	}


	return 0;
}


/*
Output
s2 is rotation of s1
Time Complexity:

Time Complexity will be n*n in the worst case, where n is the length of the string.
*/

