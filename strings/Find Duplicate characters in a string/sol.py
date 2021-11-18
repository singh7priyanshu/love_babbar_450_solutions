"""
Print all the duplicates in the input string

Write an efficient program to print all the duplicates and their counts in the input string 

Method 1: Using hashing
Algorithm: Let input string be “geeksforgeeks” 
1: Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2 
count[‘k’] = 2 
……
2: Print all the indexes from the constructed array which have values greater than 1.

"""

# Python program to count all
# duplicates from string using hashing
NO_OF_CHARS = 256

# Fills count array with
# frequency of characters
def fillCharCounts(string, count):
	for i in string:
		count[ord(i)] += 1
	return count

# Print duplicates present
# in the passed string
def printDups(string):
	
	# Create an array of size 256
	# and fill count of every character in it
	count = [0] * NO_OF_CHARS
	count = fillCharCounts(string,count)

	# Utility Variable
	k = 0

	# Print characters having
	# count more than 0
	for i in count:
		if int(i) > 1:
			print chr(k) + ", count = " + str(i)
		k += 1

# Driver program to test the above function
string = "test string"
print printDups(string)

"""
Output
s, count = 2 
t, count = 3 
Time Complexity: O(n), where n = length of the string passed

Space Complexity: O(NO_OF_CHARS)

Note: Hashing involves the use of an array of fixed size each time no matter whatever the string is. 

For example, str = “aaaaaaaaaa”. 

An array of size 256 is used for str, only 1 block out of total size (256) will be utilized to store the number of occurrences of ‘a’ in str (i.e count[‘a’] = 10). 

Rest 256 – 1 = 255 blocks remain unused. 

Thus, Space Complexity is potentially high for such cases. So, to avoid any discrepancies and to improve Space Complexity, maps are generally preferred over long-sized arrays. 

Method 2: Using Maps




Approach: The approach is the same as discussed in Method 1, but, using a map to store the count.
"""

# Python 3 program to count all duplicates
# from string using maps
from collections import defaultdict

def printDups(st):

	count = defaultdict(int)
	for i in range(len(st)):
		count[st[i]] += 1

	for it in count:
		if (count[it] > 1):
			print(it, ", count = ", count[it])

# Driver code
if __name__ == "__main__":

	st = "test string"
	printDups(st)



"""
Output
s, count = 2
t, count = 3
Time Complexity: O(N log N), where N = length of the string passed and it generally takes logN time for an element insertion in a map.

Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).
"""