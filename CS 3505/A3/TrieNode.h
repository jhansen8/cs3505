/**
  Jared Hansen
  CS3505
  Assignment 3: A Trie and the Rule-of-Three
  This class is a helper class for the Trie object. A TrieNode
  acts as the node within the Trie and keeps track of the other
  nodes. The majority of the function calls within are recursive
  calls that help create the Trie and search the Trie.
*/

#ifndef TrieNode_H
#define TrieNode_H

#include <vector>

class TrieNode {
  bool isWord;
  TrieNode* branches[26] = {}; // Stack overflow suggestion for nullptr

  /**
    Helper method takes a lowercase letter and converts to
    array index.
  */
  int charToIndex(char letter);

  /**
    Helper methode takes an array index and converts it to
    a lower case letter.
  */
  char indexToChar(int index);
public:

  /**
    Default constructor for TrieNode, sets flag to false.
  */
  TrieNode();

  /**
   Copy constructor, makes a copy of other TrieNode and creates
   a new TrieNode. Recursively copies the whole Trie.
  */
  TrieNode(const TrieNode& other);

  /**
    Deconstructor takes care of deallocating space for entire Trie.
  */
  ~TrieNode();

  /**
    Assignment operator= takes care of assigning a previous
    TrieNode to an already initialized Trie.
  */
  TrieNode& operator=(TrieNode other);

  /**
    Recursively takes care of adding a word to the Trie.
  */
  void addNode(std::string s);

  /**
    Recursively takes care of searching the tree to see if a word
    exist already. Returns a boolean as a result.
  */
  bool isAWord(std::string s);

  /**
    Helper method checks all remaining paths after path leading
    to prefix. Each word is stored into a vector to be returned.
  */
  void allWordsStartingWithPrefix(std::string input, std::string addTo,
                                              std::vector<std::string>& words);
};

#endif
