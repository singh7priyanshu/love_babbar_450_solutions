/*
Construct a trie from scratch

Trie | (Insert and Search)

Trie is an efficient information reTrieval data structure.
Using Trie, search complexities can be brought to optimal limit (key length). 
If we store keys in binary search tree, a well balanced BST will need 
time proportional to M * log N, where M is maximum string length and N is number of keys in tree. 
Using Trie, we can search the key in O(M) time. However the penalty is on Trie storage requirements 

Every node of Trie consists of multiple branches. Each branch represents a possible 
character of keys. We need to mark the last node of every key as end of word node. 
A Trie node field isEndOfWord is used to distinguish the node as end of word node. 
A simple structure to represent nodes of the English alphabet can be as following, 
// Trie node 
struct TrieNode 
{ 
     struct TrieNode *children[ALPHABET_SIZE];
     // isEndOfWord is true if the node 
     // represents end of a word 
     bool isEndOfWord; 
}; 
Inserting a key into Trie is a simple approach. Every character of the input key is 
inserted as an individual Trie node. Note that the children is an array of pointers (or references) 
to next level trie nodes. The key character acts as an index into the array children. 
If the input key is new or an extension of the existing key, we need to construct non-existing 
nodes of the key, and mark end of the word for the last node. If the input key is a prefix of 
the existing key in Trie, we simply mark the last node of the key as the end of a word. 
The key length determines Trie depth. 
 

 
Searching for a key is similar to insert operation, however, we only compare the characters 
and move down. The search can terminate due to the end of a string or lack of key in the trie. 
In the former case, if the isEndofWord field of the last node is true, then the key exists in the trie. 
In the second case, the search terminates without examining all the characters of the key, 
since the key is not present in the trie.
The following picture explains construction of trie using keys given in the example below, 
 




                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r
In the picture, every character is of type trie_node_t. For example, 
the root is of type trie_node_t, and it’s children a, b and t are filled, 
all other nodes of root will be NULL. Similarly, “a” at the next level is 
having only one child (“n”), all other children are NULL. The leaf nodes are in blue.

Insert and search costs O(key_length), however the memory requirements of Trie 
is O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie. There are 
efficient representation of trie nodes (e.g. compressed trie, ternary search tree, etc.) 
to minimize memory requirements of trie.


*/
<script>
// Javascript implementation of search and insert operations
// on Trie

// Alphabet size (# of symbols)
let ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
	constructor()
	{
		this.isEndOfWord = false;
		this.children = new Array(ALPHABET_SIZE);
		for (let i = 0; i < ALPHABET_SIZE; i++)
			this.children[i] = null;
	}
}

let root;

// If not present, inserts key into trie
	// If the key is prefix of trie node,
	// just marks leaf node
function insert(key)
{
	let level;
		let length = key.length;
		let index;
	
		let pCrawl = root;
	
		for (level = 0; level < length; level++)
		{
			index = key[level].charCodeAt(0) - 'a'.charCodeAt(0);
			if (pCrawl.children[index] == null)
				pCrawl.children[index] = new TrieNode();
	
			pCrawl = pCrawl.children[index];
		}
	
		// mark last node as leaf
		pCrawl.isEndOfWord = true;
}

// Returns true if key presents in trie, else false
function search(key)
{
	let level;
		let length = key.length;
		let index;
		let pCrawl = root;
	
		for (level = 0; level < length; level++)
		{
			index = key[level].charCodeAt(0) - 'a'.charCodeAt(0);
	
			if (pCrawl.children[index] == null)
				return false;
	
			pCrawl = pCrawl.children[index];
		}
	
		return (pCrawl.isEndOfWord);
}

// Driver
// Input keys (use only 'a' through 'z' and lower case)
let keys = ["the", "a", "there", "answer", "any",
				"by", "bye", "their"];

let output = ["Not present in trie", "Present in trie"];


root = new TrieNode();

// Construct trie
let i;
for (i = 0; i < keys.length ; i++)
	insert(keys[i]);

// Search for different keys
if(search("the") == true)
	document.write("the --- " + output[1]+"<br>");
else
	document.write("the --- " + output[0]+"<br>");

if(search("these") == true)
	document.write("these --- " + output[1]+"<br>");
else
	document.write("these --- " + output[0]+"<br>");

if(search("their") == true)
	document.write("their --- " + output[1]+"<br>");
else
	document.write("their --- " + output[0]+"<br>");

if(search("thaw") == true)
	document.write("thaw --- " + output[1]+"<br>");
else
	document.write("thaw --- " + output[0]+"<br>");



</script>

/*

Output :

the --- Present in trie
these --- Not present in trie
their --- Present in trie
thaw --- Not present in trie

*/