#include <bits/stdc++.h>

using namespace std;

/*
    Approach 1: using Trie and Queue to keep track of starting states
    TIME LIMIT EXCEEDED.
*/


class Node
{

public:
    char data;
    bool isTerminal;
    vector<Node *> children;

    Node(int ch)
    {
        this->data = ch;
        this->isTerminal = false;
        this->children.resize(26, NULL);
    }
};

class Trie
{

    Node *root;
    string s;
    int len;

public:
    Trie(string s)
    {
        this->root = new Node('#');
        this->s = s;
        this->len = s.length();
    }

    void addWord(string word)
    {

        Node *crawler = this->root;
        int n = word.length();

        if (n == 0)
            return;

        for (int i = 0; i < n; i++)
        {

            int index = word[i] - 'a';

            if (crawler->children[index] == NULL)
            {
                crawler->children[index] = new Node(word[i]);
            }

            crawler = crawler->children[index];
        }

        crawler->isTerminal = true;
    }

    void traverseString(int index, queue<int> &charQueue)
    {
        Node *crawler = this->root;

        int idx = index;

        while (idx < this->len)
        {

            int i = this->s[idx] - 'a';

            if (crawler->children[i] != NULL)
            {

                idx++;

                if (crawler->children[i]->isTerminal)
                {

                    charQueue.push(idx);
                }

                crawler = crawler->children[i];
            }
            else
            {
                return;
            }
        }
    }
};

class Solution1
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        Trie dict(s);

        for (auto &word : wordDict)
        {
            dict.addWord(word);
        }

        queue<int> charQueue;

        charQueue.push(0);

        int n = s.length();

        while (true)
        {

            int i = charQueue.front();
            charQueue.pop();

            if (i == n)
            {
                return true;
            }

            dict.traverseString(i, charQueue);

            if (charQueue.empty())
            {
                return false;
            }
        }

        return true;
    }
};


