/**
  Jared Hansen
  CS3505
  Assignment 3: A Trie and the Rule-of-Three
  This class sets up and manages a Trie object. A Trie will act as
  a dictionary and keep track of unique words added. This Allows
  the caller to add words and check other words for validity.
*/

#include <iostream>
#include <cstring>
#include "TrieNode.h"
#include "Trie.h"

/**
  Constructor for a Trie object, it sets up a root node
  for the Trie structure.
*/
Trie::Trie() {
  root = new TrieNode();
}

/**
Copy constructor, makes a copy of other Trie and creates
a new Trie.
*/
Trie::Trie(const Trie& other) {
  root = new TrieNode(*(other.root));
}

/**
  Deconstructor takes care of deallocating space.
*/
Trie::~Trie() {
  delete root;
}

/**
  Assignment operator= takes care of assigning a previous
  Trie to an already initialized Trie.
*/
Trie& Trie::operator=(Trie other) {
  std::swap(root, other.root);
  return *this;
}

/**
  Adds a word to the Trie as long as the word is not empty.
*/
void Trie::addAWord(std::string word) {
  if (!word.empty())
    root->addNode(word);
  else
    return;
}

/**
  Checks to see if a word is contained in the Trie.
*/
bool Trie::isAWord(std::string word) {
  if (!word.empty())
    return root->isAWord(word);
  else
    return false;
}

/**
  Returns all possible words beginning with the prefix being passed in
  as a parameter. The prefix can be a word itself and will be included.
*/
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix) {
  std::vector<std::string> words;
  root->allWordsStartingWithPrefix(prefix, prefix, words);
  return words;
}
