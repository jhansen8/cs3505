/**
  Jared Hansen
  CS3505
  Assignment 3: A Trie and the Rule-of-Three
  This program takes in input from two files, the first one being a
  source for the Dictionay and the second one a source for a list of
  words that need to be checked to see if they are contained in the
  dictionary. It also does basic checks to verify functionality of
  the rule of three.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "Trie.h"

using namespace std;

/**
  Main will initiate the program and run when executed
*/
int main(int argc, char **argv) {
  // local variables to be used
  std::string line;
  Trie tree;

  // for file reading
  ifstream dictionaryFile;
  ifstream testFile;

  // Verify number of arguments is as needed
  if (argc != 3){
    cout << "Error reading files" << endl;
    exit(1);
  }

  // Attempt to open the first file, exit upon failure
  dictionaryFile.open(argv[1]);
  if (!dictionaryFile) {
    cout << "Unable to open file:" << argv[1] << endl;
    exit(1);
  }

  // Read in words and add to Trie
  while ( getline(dictionaryFile,line)) {
    tree.addAWord(line);
  }
  dictionaryFile.close();

  // Attempt to open the second file, exit upon failure
  testFile.open(argv[2]);
  if (!testFile) {
    cout << "Unable to open file:" << argv[2] << endl;
    exit(1);
  }

  // Test each word in file to se if it is in the Trie
  while ( getline(testFile,line)) {
    // Confirm word is found
    if (tree.isAWord(line)) {
      cout << line << " is found." << endl;
    }
    else {
      // If not in trie as word, check to see if it is a prefix
      cout << line << " is not found, did you mean:" << endl;
      std::vector<std::string> words = tree.allWordsStartingWithPrefix(line);

      // Display the alternatives
      if (!words.empty()) {
        for (vector<std::string>::iterator it = words.begin() ; it != words.end(); ++it)
          cout << "   " << *it << "\n";
      }
      else {
        // display there were no alternatives
        cout << "   " << "No alternatives found" << endl;
      }
    }
  }
  testFile.close();


  // Use copy constructor and demonstrate
  Trie copyTree(tree);

  // Exact copy
  cout << "Show tree copied succesfully to copyTree:" << endl;
  cout << "   Should find (1): " << copyTree.isAWord("yesterday") << endl;
  cout << "   Should not find (0): " << copyTree.isAWord("yesterdayy") << endl;

  // Can modify without affecting original Trie
  copyTree.addAWord("aaaaaaa");
  cout << "Show reference two distinct tries:" << endl;
  cout << "   Should find in copyTree (1): " << copyTree.isAWord("aaaaaaa") << endl;
  cout << "   Should not find in tree (0): " << tree.isAWord("aaaaaaa") << endl;

  // Use assignment operator and demonstrate
  Trie toAssign;
  toAssign = copyTree;

  // exact copy
  cout << "Show copyTree assigned succesfully to toAssign:" << endl;
  cout << "   Should find (1): " << toAssign.isAWord("yesterday") << endl;
  cout << "   Should not find (0): " << toAssign.isAWord("yesterdayy") << endl;

  // Can modify without affecting original Tries
  toAssign.addAWord("bbbb");
  cout << "Show reference two distinct tries:" << endl;
  cout << "   Should find in toAssign (1): " << toAssign.isAWord("bbbb") << endl;
  cout << "   Should not find in copyTree (0): " << copyTree.isAWord("bbbb") << endl;

  // Show deconstructor works
  Trie * treeCopy = new Trie();
  delete treeCopy;
  // Uncomment to see that deconstructor works, thows error with desanitize
  // treeCopy->addAWord("hi");
  // cout << "Should not find (0): " << treeCopy->isAWord("hi") << endl;
}
