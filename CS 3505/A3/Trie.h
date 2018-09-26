/**
  Jared Hansen
  CS3505
  Assignment 3: A Trie and the Rule-of-Three
  This class sets up and manages a Trie object. A Trie will act as
  a dictionary and keep track of unique words added. This Allows
  the caller to add words and check other words for validity
*/

#ifndef Trie_H
#define Trie_H

#include <vector>
#include "TrieNode.h"

class Trie {
  TrieNode* root;
public:

  /**
    Constructor for a Trie object, it sets up a root node
    for the Trie structure.
  */
  Trie();

  /**
   Copy constructor, makes a copy of other Trie and creates
   a new Trie.
  */
  Trie(const Trie& other);

  /**
    Deconstructor takes care of dallocating space.
  */
  ~Trie();

  /**
    Assignment operator= takes care of assigning a previous
    Trie to an already initialized Trie.
  */
  Trie& operator=(Trie other);

  /**
    Adds a word to the Trie as long as the word is not empty.
  */
  void addAWord(std::string word);

  /**
    Checks to see if a word is contained in the Trie.
  */
  bool isAWord(std::string word);

  /**
    Returns all possible words beginning with the prefix being passed in
    as a parameter. The prefix can be a word itself and will be included.
  */
  std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
};

#endif
