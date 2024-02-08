#pragma once
#include <string>;
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};


class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(string word);
    void printAllWords();
    void printAllWordsUtil(TrieNode* node, string word);
    bool remove(string word);
    bool removeUtil(TrieNode* node, string& word, int level);
    void printAllWordsThatStartWith(string prefix);
    void printAllWordsWithPrefix(TrieNode* node, string prefix);

    void removeEvenLengthWords();
    void removeEvenLengthWordsUtil(TrieNode* node, string prefix);
    bool contains(string word);

    void visualizeTrie();
    void visualizeTrieUtil(TrieNode* node, int level);
private:
    bool isLastNode(TrieNode* node) const;
};


