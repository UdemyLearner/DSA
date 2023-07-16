#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root; // this trieNode * class will store 3 val a above ;
    Trie()
    {
        root = new TrieNode('\n');
    }

    void insertWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        // case 1 if word is present inside the trie; just shift the child to next
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // case 2 we have to insert the word inside the trie; and then shift child to next node;
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1)); // recursion ;
    }

    void insert(string word)
    {
        insertWord(root, word);
    }

    // searchWord
    bool searchWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode *child;
        // case 1 if present then continue;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else//absent
            return false;

        // recursion
        return searchWord(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchWord(root, word);
    }

    bool code(TrieNode *root, string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }
        int index = prefix[0] - 'a';
        TrieNode *child;
        // case 1 if present then continue;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else//absent
            return false;

        // recursion
        return code(child, prefix.substr(1));
    }
    bool startsWith(string prefix)
    {
        return code(root, prefix);
    }
};

int main(int argc, char const *argv[])
{
    Trie *t;
    t->insert("apple");
    cout<<"search" <<t->search("apple") << endl;
    return 0;
}
