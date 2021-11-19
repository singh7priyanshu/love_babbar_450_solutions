"""
Construct a trie from scratch

Trie | (Insert and Search)

Trie is an efficient information reTrieval data structure.
Using Trie, search complexities can be brought to optimal limit (key length). 
If we store keys in binary search tree, a well balanced BST will need 
time proportional to M * log N, where M is maximum string length and N is number of keys in tree. 
Using Trie, we can search the key in O(M) time. However the penalty is on Trie storage requirements 

Every node of Trie consists of multiple branches. Each branch represents a 
possible character of keys. We need to mark the last node of every key as end of word node. 
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
Inserting a key into Trie is a simple approach. Every character of the input key 
is inserted as an individual Trie node. Note that the children is an array of pointers 
(or references) to next level trie nodes. The key character acts as an index into the array children. 
If the input key is new or an extension of the existing key, we need to construct non-existing 
nodes of the key, and mark end of the word for the last node. 
If the input key is a prefix of the existing key in Trie, we simply mark the last node of the key
as the end of a word. The key length determines Trie depth. 
 

 
Searching for a key is similar to insert operation, however, we only compare the 
characters and move down. The search can terminate due to the end of a string or 
lack of key in the trie. In the former case, if the isEndofWord field of the last node is true, 
then the key exists in the trie. In the second case, 
the search terminates without examining all the characters of the key, 
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
all other nodes of root will be NULL. Similarly, “a” at the next level 
is having only one child (“n”), all other children are NULL. The leaf nodes are in blue.

Insert and search costs O(key_length), however the memory requirements of Trie 
is O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie. There are 
efficient representation of trie nodes (e.g. compressed trie, ternary search tree, etc.) 
to minimize memory requirements of trie.


"""

# Python program for insert and search
# operation in a Trie

class TrieNode:
	
	# Trie node class
	def __init__(self):
		self.children = [None]*26

		# isEndOfWord is True if node represent the end of the word
		self.isEndOfWord = False

class Trie:
	
	# Trie data structure class
	def __init__(self):
		self.root = self.getNode()

	def getNode(self):
	
		# Returns new trie node (initialized to NULLs)
		return TrieNode()

	def _charToIndex(self,ch):
		
		# private helper function
		# Converts key current character into index
		# use only 'a' through 'z' and lower case
		
		return ord(ch)-ord('a')


	def insert(self,key):
		
		# If not present, inserts key into trie
		# If the key is prefix of trie node,
		# just marks leaf node
		pCrawl = self.root
		length = len(key)
		for level in range(length):
			index = self._charToIndex(key[level])

			# if current character is not present
			if not pCrawl.children[index]:
				pCrawl.children[index] = self.getNode()
			pCrawl = pCrawl.children[index]

		# mark last node as leaf
		pCrawl.isEndOfWord = True

	def search(self, key):
		
		# Search key in the trie
		# Returns true if key presents
		# in trie, else false
		pCrawl = self.root
		length = len(key)
		for level in range(length):
			index = self._charToIndex(key[level])
			if not pCrawl.children[index]:
				return False
			pCrawl = pCrawl.children[index]

		return pCrawl.isEndOfWord

# driver function
def main():

	# Input keys (use only 'a' through 'z' and lower case)
	keys = ["the","a","there","anaswe","any",
			"by","their"]
	output = ["Not present in trie",
			"Present in trie"]

	# Trie object
	t = Trie()

	# Construct trie
	for key in keys:
		t.insert(key)

	# Search for different keys
	print("{} ---- {}".format("the",output[t.search("the")]))
	print("{} ---- {}".format("these",output[t.search("these")]))
	print("{} ---- {}".format("their",output[t.search("their")]))
	print("{} ---- {}".format("thaw",output[t.search("thaw")]))

if __name__ == '__main__':
	main()


"""

Output :

the --- Present in trie
these --- Not present in trie
their --- Present in trie
thaw --- Not present in trie

"""
