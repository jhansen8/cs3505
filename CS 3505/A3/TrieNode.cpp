/**
  Jared Hansen
  CS3505
  Assignment 3: A Trie and the Rule-of-Three
  This class is a helper class for the Trie object. A TrieNode
  acts as the node within the Trie and keeps track of the other
  nodes. The majority of the function calls within are recursive
  calls that help create the Trie and search the Trie.
*/

#include <iostream>
#include <cstring>
#include "TrieNode.h"

/**
  Helper method takes a lowercase letter and converts to
  array index.
*/
int TrieNode::charToIndex(char letter) {
  return letter - 'a';
}

/**
  Helper methode takes an array index and converts it to
  a lower case letter.
*/
char TrieNode::indexToChar(int index) {
  return index + 'a';
}

/**
  Default constructor for TrieNode, sets flag to false.
*/
TrieNode::TrieNode() {
  isWord = false;
}

/**
 Copy constructor, makes a copy of other TrieNode and creates
 a new TrieNode. Recursively copies the whole Trie.
*/
TrieNode::TrieNode(const TrieNode& other) {
  isWord = other.isWord;
  for (int i = 0; i < 26; i++){
    if(other.branches[i] != nullptr)
    {
      branches[i] = new TrieNode(*(other.branches[i]));
    }
  }
}

/**
  Deconstructor takes care of deallocating space for entire Trie.
*/
TrieNode::~TrieNode() {
  for (int i = 0; i < 26; i++){
    if(branches[i] != nullptr)
    {
      delete branches[i];
    }
  }
}

/**
  Assignment operator= takes care of assigning a previous
  TrieNode to an already initialized Trie.
*/
TrieNode& TrieNode::operator=(TrieNode other) {
std::swap(isWord, other.isWord);
std::swap(branches, other.branches);
return *this;
}

/**
  Recursively takes care of adding a word to the Trie.
*/
void TrieNode::addNode(std::string s) {
  // if the end of the string has been reached, set flag
  if (s.empty()) {
    isWord = true;
    return;
  }
  else {
    // check to see if node already exist for this path
    int index = charToIndex(s[0]);
    if (branches[index] == nullptr) {
      // Create a new node and call method again on substring
      branches[index] = new TrieNode();
      branches[index]->addNode(s.substr(1));
    }
    else {
      // Call method again if node already exist
      branches[index]->addNode(s.substr(1));
    }
  }
}

/**
  Recursively takes care of searching the tree to see if a word
  exist already. Returns a boolean as a result.
*/
bool TrieNode::isAWord(std::string s) {
  // If end of the string has been reached, check flag.
  if(s.empty()) {
    return isWord;
  }
  else {
    // Check to see if path contunies to exist, else return false
    int index = charToIndex(s[0]);
    if(branches[index] == nullptr) {
      return false;
    }
    else {
      // Continue on path and call method again
      return branches[index]->isAWord(s.substr(1));
    }
  }
}

/**
  Helper method checks all remaining paths after path leading
  to prefix. Each word is stored into a vector to be returned.
*/
void TrieNode::allWordsStartingWithPrefix(std::string input,
                                                std::string addTo,
                                                std::vector<std::string>& words) {
  // Check to see if current location on path has an valid word
  if(input.empty()) {
    // Add word to vector
    if (isWord) {
      words.push_back(addTo);
    }

    // Recursively check every possible branch for a new path to follow
    for (int i = 0; i < 26; i++){
      // Only check non-null paths
      if(branches[i] != nullptr)
      {
        // Add current char to word
        std::string temp = addTo + indexToChar(i);
        branches[i]->allWordsStartingWithPrefix(input, temp, words);
      }
    }
  }
  else {
    // Move past all chars in the prefix to begin search
    int index = charToIndex(input[0]);
    if(branches[index] != nullptr) {
      branches[index]->allWordsStartingWithPrefix(input.substr(1),
                                                          addTo, words);
    }
  }
}
