#include <iostream>
#include "TrieTree.h"
using namespace std;

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void Trie::printAllWords() {
    string word;
    printAllWordsUtil(root, word);
}

void Trie::printAllWordsUtil(TrieNode* node, string word) {
    if (node->isEndOfWord) {
        cout << word << endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            printAllWordsUtil(node->children[i], word + c);
        }
    }
}

bool Trie::remove(string word) {
    return removeUtil(root, word, 0);
}

bool Trie::removeUtil(TrieNode* node, string& word, int level) {
    if (level == word.length()) {
        if (!node->isEndOfWord) return false;
        node->isEndOfWord = false;

        return isLastNode(node);
    }
    else {
        int index = word[level] - 'a';
        if (!node->children[index]) return false;

        bool shouldDeleteCurrentNode = removeUtil(node->children[index], word, level + 1);

        if (shouldDeleteCurrentNode && !node->isEndOfWord) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !isLastNode(node);
        }

        return false;
    }
}

bool Trie::contains(string word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) return false;
        node = node->children[index];
    }
    return node->isEndOfWord;
}

void Trie::printAllWordsThatStartWith(std::string prefix) {
    string resultPrefix = "";
    TrieNode* current = root;
    for (char c : prefix) {
        int index = c - 'a';
        if (!current->children[index]) {
            cout << "No words found with the given prefix" << endl;
            return;
        }
        else {
            resultPrefix += c;
            current = current->children[index];
        }
    }
    printAllWordsWithPrefix(current, resultPrefix);

}

void Trie::printAllWordsWithPrefix(TrieNode* node, string prefix) {
    if (node == nullptr) {
        return;
    }
    else {
        if (node->isEndOfWord) {
            cout << prefix << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            char c = 'a' + i;
            printAllWordsWithPrefix(node->children[i], prefix + c);
        }
    }
}


bool Trie::isLastNode(TrieNode* node) const {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return false;
        }
    }
    return true;
}

void Trie::removeEvenLengthWordsUtil(TrieNode* node, string prefix) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            removeEvenLengthWordsUtil(node->children[i], prefix + char('a' + i));
        }
    }

    if (node->isEndOfWord && prefix.length() % 2 == 0) {
        remove(prefix);
    }
}

void Trie::removeEvenLengthWords() {
    removeEvenLengthWordsUtil(root, "");
}

void Trie::visualizeTrie() {
    visualizeTrieUtil(root, 0);
}

void Trie::visualizeTrieUtil(TrieNode* node, int level) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            for (int j = 0; j < level; j++) {
                cout << "  "; // ѕробелы дл€ отступа в зависимости от уровн€
            }

            char c = 'a' + i;
            cout << c << " -> ";

            if (node->children[i]->isEndOfWord) {
                cout << "(" << c << ")";
            }

            cout << endl;

            visualizeTrieUtil(node->children[i], level + 1);
        }
    }
}