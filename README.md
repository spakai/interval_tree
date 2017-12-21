##Synopsis
Prefix tree is one of the most popular data structures on words.
It uses the trie data structure to search a string from a collection
of strings. Search time is O(m) where m is the length of the string
being sought.

##Motivation
I want to determine the location of a landline number with longest prefix match which can also return an exact match.

|Number | Location|
|---   |---      |
|60    |Malaysia |
|605   |Perak    |
|6055  |Ipoh     |
|605527|Rishah   |
|605528|Silibin  |

So if i have a number 6055286892 and i want to know it's longest prefix match , the program should return me the location = Silibin. The number 60354545454 will give me the location Malaysia. 


##Code Design
A trie can be represented with the linked list. Here, we will represent a trie which stores the words starting with a particular character. Each node of a trie can be represented by the following structure.

```cpp
struct Node {
    char chr;
    std::string word;
    std::vector<Node*> child;
};
```
The child is an vector meant to hold the address of X possible children of the node. If we are only storing characters from 0-9 then each Node has 10 children so index 0 to 9 of the vector is defaulted to nullptr. 

Each node has one character assigned to it and if it is the last character of a word, the word is assigned to the word variable.

This way, the program doesn't need to keep track of individual characters it has traversed.


The PrefixTree class uses the Node struct to do two things

###insert

The string is broken into individual characters and stored in individual nodes. 

There are two paths in the insert node
- If the character does not already exist, memory is allocated and the character is assigned.
- If the character already exists , then the code processes the next character of the word.
- If it is the last character of a word , the whole string is assigned to the word variable. 

###search

This function finds the best prefix match value. The string is again broken into individual characters and traversed thru the tree.

If the node where the expected character is empty, it breaks and returns the longest match prefix which could or could not be an exact match. 


##Heap Memory Allocation and Deallocation
The PrefixTree class creates the root node on creation and deletes it during destruction.
This will trigger a cascade destruction of the root's children which is handled by the Node's destructor.

To check for memory leak I used the command 
```
valgrind --tool=memcheck --leak-check=yes --show reachable=yes --num-callers=20 --track-fds=yes ./test
```

##Code coverage
To generate code coverage report do the following:


##Required software 
- GTest
- Valgrind
- C++ 11 compiler
- CMake
