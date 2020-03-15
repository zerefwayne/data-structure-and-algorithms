#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    bool isTerminal;
    bool isRoot;
    vector<Node *> children;

    Node(char ch, int alphabetCount)
    {
        this->data = ch;
        this->isRoot = false;
        this->isTerminal = false;
        this->children.resize(alphabetCount, NULL);
    }
};

class Trie
{

    Node *root;
    int alphabetCount;

public:
    Trie(int alphabetCount)
    {
        this->root = new Node('-', alphabetCount);
        this->alphabetCount = alphabetCount;
        this->root->isRoot = true;
    }

    bool insertWord(string word)
    {

        Node *crawler = this->root;
        int n = word.length();

        if (n == 0)
            return false;

        for (int i = 0; i < n; i++)
        {

            int index = word[i] - 'a';

            if (crawler->children[index] == NULL)
            {

                crawler->children[index] = new Node(word[i], this->alphabetCount);
            }

            crawler = crawler->children[index];
        }

        crawler->isTerminal = true;
    }

    void dfsUtility(Node *crawler, string &current, vector<string> &words)
    {

        if (crawler->isRoot)
        {

            for (int i = 0; i < this->alphabetCount; i++)
            {

                if (crawler->children[i] != NULL)
                {
                    dfsUtility(crawler->children[i], current, words);
                }
            }
        }
        else
        {
            current.push_back(crawler->data);

            if (crawler->isTerminal)
            {
                words.emplace_back(current);
            }

            for (int i = 0; i < this->alphabetCount; i++)
            {

                if (crawler->children[i] != NULL)
                {
                    dfsUtility(crawler->children[i], current, words);
                }
            }

            current.pop_back();
        }
    }

    void printAllWords()
    {

        vector<string> words;
        string current = "";

        this->dfsUtility(this->root, current, words);

        cout << "Words:\n\n";

        for (auto &word : words)
        {
            cout << word << '\n';
        }
    }
};

int main()
{

    Trie trie(26);

    trie.insertWord("hello");
    trie.insertWord("helloman");
    trie.insertWord("mamaaa");
    trie.insertWord("carryon");
    trie.insertWord("matters");
    trie.insertWord("goodbye");
    trie.insertWord("shivers");

    trie.printAllWords();

    return 0;
}