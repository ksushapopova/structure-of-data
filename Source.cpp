#include "TrieTree.h"
#include <iostream>
#include <string>;

int main() {

    // Create a trie
    Trie trie;

    // Insert some words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");

    std::cout << "Enter the task number: " << std::endl;
    std::cout << "1.Add word. " << std::endl;
    std::cout << "2.Delete word." << std::endl;
    std::cout << "3.Print tree." << std::endl;
    std::cout << "4.Print all words. " << std::endl;
    std::cout << "5.Delete even-lenght word." << std::endl;
    bool tmp = true;
    while (tmp == true)
    {
        int x;
        std::cout << "Enter the task number: " << std::endl;
        std::cin >> x;
        switch (x) {
        case 1:
        {
            string i;
            std::cout << "enter word ";
            std::cin >> i;
            trie.insert(i);
            std::cout << "------------------" << std::endl;
            break;
        }
        case 2:
        {
            string j;
            std::cout << "enter word ";
            std::cin >> j;
            trie.remove(j);
            std::cout << "------------------" << std::endl;
            break;
        }
        case 3:
        {
            trie.visualizeTrie();
            std::cout << "------------------" << std::endl;
            break;
        }
        case 4:
            trie.printAllWords();
            std::cout << "------------------" << std::endl;
            break;
        case 5:
            trie.removeEvenLengthWords();
            std::cout << "------------------" << std::endl;
            break;
        case 0:
            tmp = false;
        }
    }

}