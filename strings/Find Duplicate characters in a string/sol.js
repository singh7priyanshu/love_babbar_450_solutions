/*
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

*/


<script>
	// Javascript program to count all duplicates
	// from string using hashing
	
	let NO_OF_CHARS = 256;
	
	/* Print duplicates present in
	the passed string */
	function printDups(str)
	{
		
		// Create an array of size 256 and
		// fill count of every character in it
		let count = new Array(NO_OF_CHARS);
		count.fill(0);
		
		for (let i = 0; i < str.length; i++)
			count[str[i].charCodeAt()]++;
			
		for (let i = 0; i < NO_OF_CHARS; i++)
		{
			if(count[i] > 1)
			{
				document.write(String.fromCharCode(i) + ", " +
				"count = " + count[i] + "</br>");
			}
		}	
	}
	
	let str = "test string";
	printDups(str);
		
</script>

/*
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
*/

<script>
//Javascript Implementation
// to count all duplicates
// from string using maps

function printDups(str)
{
	var count = {};
	for (var i = 0; i < str.length; i++) {
		count[str[i]] = 0;
	}
	
	for (var i = 0; i < str.length; i++) {
		count[str[i]]++;
	}

	for (var it in count) {
		if (count[it] > 1)
			document.write(it + ", count = " + count[it] + "<br>");
	}
}
/* Driver code*/
var str = "test string";
printDups(str);


</script>

/*
Output
s, count = 2
t, count = 3
Time Complexity: O(N log N), where N = length of the string passed and it generally takes logN time for an element insertion in a map.

Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).
*/