CC = g++
CFLAGS = -Wall -fsanitize=undefined,address

TrieTest: main.cpp Trie.o TrieNode.o
	$(CC) $(CFLAGS) -o TrieTest main.cpp Trie.o TrieNode.o

Trie.o: Trie.cpp Trie.h TrieNode.h
	$(CC) $(CFLAGS) -c Trie.cpp

TrieNode: TrieNode TrieNode.h
	$(CC) $(CFLAGS) -c TrieNode.cpp

clean:
	rm -f *.o *.a test

test: TrieTest
	./TrieTest dictionary.txt testwords.txt
