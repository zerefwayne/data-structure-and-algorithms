```cpp
void generate(vector<string> &res, string &curr, unordered_map<char, vector<char>> &keyboard, int start, string A, int n)
{

    if (start == n)
    {
        res.emplace_back(curr);
        return;
    }

    for (auto c : keyboard[A[start]])
    {

        curr.push_back(c);

        generate(res, curr, keyboard, start + 1, A, n);

        curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A)
{

    unordered_map<char, vector<char>> keyboard;

    keyboard['1'].insert(keyboard['1'].begin(), {'1'});
    keyboard['2'].insert(keyboard['2'].begin(), {'a', 'b', 'c'});
    keyboard['3'].insert(keyboard['3'].begin(), {'d', 'e', 'f'});

    keyboard['4'].insert(keyboard['4'].begin(), {'g', 'h', 'i'});
    keyboard['5'].insert(keyboard['5'].begin(), {'j', 'k', 'l'});
    keyboard['6'].insert(keyboard['6'].begin(), {'m', 'n', 'o'});

    keyboard['7'].insert(keyboard['7'].begin(), {'p', 'q', 'r', 's'});
    keyboard['8'].insert(keyboard['8'].begin(), {'t', 'u', 'v'});
    keyboard['9'].insert(keyboard['9'].begin(), {'w', 'x', 'y', 'z'});

    keyboard['0'].insert(keyboard['0'].begin(), {'0'});

    vector<string> res;
    string curr;

    generate(res, curr, keyboard, 0, A, A.length());

    return res;
}
```