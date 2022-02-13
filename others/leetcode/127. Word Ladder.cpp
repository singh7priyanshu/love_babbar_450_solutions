/*
127. Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary 
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", 
which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/

/*

Brief note about Question-

We have to return the number of words in the shortest transformation sequence from beginWord 
to endWord from the word List, or 0 if no such sequence exists.
Let's take an example not given in question -
Suppose, beginWord = "aa", endWord = "cc" & wordList = ["ba", "da", "bc", "dc", "db", "ac", "cc"]

So, the answer should be 3 as (aa --> ac --> cc)
You can try out many other combinations also, but this is the shortest transformation.
How this is a graph Problem?

If we assume each word as node and each tansformation as an edge then we have to just 
find the shortest path from a node to anthor node i.e from begin word to end word with 
all edges having weight as 1.
So, if graph problem what we are going to use, DFS or BFS ?

DFS is not used to find out the shortest distance in graph but only in TREES because we have 
unique paths between nodes in a TREE but we can have exponential number of unique paths between 
2 nodes in a graph. So we will use BFS.
You can refer to this codeforces blog also for better understnding -
Why DFS can't be used for shortest distance on graph, but works on tree
How we will Implement it?

ans :  "Because in the tree there is only one path from one verticle to another. 
        DFS is taking one way and going by that way (there's no gurantee that way is the best), 
        but in tree there is as that way is unique."

First we will store all the letters of wordList into a unordered set. It is used to decrease the 
final time complexity as find and erase will work in O(1) in unordered set.
While inserting all the letters into the set, we will check whether the endWord is present in our 
wordList or not.If not,then return 0saying that this transformation is not possible.
We will declare two variables named as depth and levelsize. Depth indicates the depth of the queue 
which we are exploring & levelsize indicates the how many nodes are their at a certain level of the 
graph.
For BFS, we requiredqueue and intially we will push our beginWord into the our queue.
Now, for each word into the queue we will replace each position with every alhapbet and look into 
our set that the word other than we replacing are present into our set or not.
If yes, we will erase that word from the set and push it into our queue.
If at any certain position we will find the same word as same as our endWord we will simply 
return depth + 1 as our answer because depth is the nothing but suggests us the queue which 
we are exploring.
And at last, if we still not able to find our endWord we will return 0 as answer.
I hope you got the basic idea how we will implement BFS, please see commented code for more 
clarification.
Time Complexity --> O( 26 * n * n * w)
where 26 represents that we are trying each possibility of alphabet
first n is the length of word 
anthor n for string compare and w for number of words.

Space Complexity --> O(n) // we are using unordered set from our side
It paases [ 50 / 50 ] in built test cases
Code (C++)

*/


// for speeding up our code
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet; // declare an unordered set
        
        bool isPresent = false; // to find whether end word is present in word list or not
        
        // Inserting all words from wordList to wordSet
        for(string word: wordList)
        {
            if(endWord.compare(word) == 0) // if end word is present in wordList
            {
                isPresent = true;
            }
            
            wordSet.insert(word); // Inserting each word in wordSet
        }
        
        if(isPresent == false) // if end word is not present in worrd List
            return 0;
        
        queue<string> q; // declare an queue, for BFS traversal
        q.push(beginWord); // push begi word into our queue
        
        int depth = 0; // for telling depth of the queue we are exploring
        
        // Implementing BFS
        while(q.empty() == false)
        {
            depth = depth + 1; // if one level is over increment depth
            
            int levelSize = q.size(); // number of words present at a level
            
            // travelling in each level
            while(levelSize--)
            {
                string curr = q.front();
                q.pop();
                
                // checking for all possible depth word
                for(int i = 0; i < curr.length(); i++) // for each index
                {
                    string temp = curr; 
                    
                    //checking out each possibility of alphabet
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        
                        if(curr.compare(temp) == 0) // skipping the same word
                            continue;
                        
                        if(temp.compare(endWord) == 0) // if matches with end word
                            return depth + 1;
                        
                        // if present in word set
                        if(wordSet.find(temp) != wordSet.end())
                        {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0; // and at last, we still not able to find our end word.
    }
};

