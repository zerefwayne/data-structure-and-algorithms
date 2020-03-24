[Leetcode Weekly Contest 98 - Find and Replace Pattern](https://leetcode.com/contest/weekly-contest-98/problems/find-and-replace-pattern/)

## Approach 1: Creating a vector of patterns and equating them. time O(pat_length*words) space O(pat_length) Passed

```cpp
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {

        vector<string> res;

        vector<int> template_pat;

        unordered_map<char, int> charCount;

        int counter = 0;

        for (auto &c : pattern)
        {

            if (charCount.find(c) == charCount.end())
            {
                charCount[c] = counter++;
            }

            template_pat.emplace_back(charCount[c]);
        }

        vector<int> patw;

        for (auto &word : words)
        {

            charCount.clear();
            patw.clear();
            counter = 0;

            for (auto &c : word)
            {

                if (charCount.find(c) == charCount.end())
                {
                    charCount[c] = counter++;
                }

                patw.emplace_back(charCount[c]);
            }

            if (patw == template_pat)
            {
                res.emplace_back(word);
            }
        }

        return res;
    }
};
```

## Approach 2: BEST zip() function Python to check isomorphism

```py
b = pattern
        def is_iso(a):
            return len(a) == len(b) and len(set(a)) == len(set(b)) == len(set(zip(a, b)))
        return filter(is_iso, words)
```

## Approach 3: Concise C++ Normalizing String Solution

```cpp
string toPattern(string word)
{
    map<char, char> M;
    int curr = 97;
    for (char &c : word)
        if (M.count(c) == 0)
            M[c] = (char)curr++;
    for (int i = 0; i < word.length(); i++)
        word[i] = M[word[i]];
    return word;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    string p = toPattern(pattern);
    vector<string> res;
    for (string &w : words)
        if (toPattern(w).compare(p) == 0)
            res.push_back(w);
    return res;
}
```