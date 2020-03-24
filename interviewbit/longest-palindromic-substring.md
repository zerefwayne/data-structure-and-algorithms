## Approach 1: Manacher's Algorithm O(n) time O(n) space

```cpp
string preprocess(string str)
{

    int n = str.length();

    string converted = "$#";

    for (auto &c : str)
    {
        converted.push_back(c);
        converted.push_back('#');
    }

    converted.push_back('@');

    return converted;
}

string manachers(string original, string str)
{

    int n = str.length();
    vector<int> p(n, 0);

    int C = 0;
    int R = 0;

    for (int i = 1; i < n - 1; i++)
    {

        int mirror = 2 * C - i;

        if (R > i)
        {
            p[i] = min(R - i, p[mirror]);
        }

        while (str[i + (1 + p[i])] == str[i - (1 + p[i])])
        {
            p[i]++;
        }

        if (i + p[i] > R)
        {
            C = i;
            R = i + p[i];
        }
    }

    int length = 0;
    int center = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (p[i] > length)
        {
            length = p[i];
            center = i;
        }
    }

    return original.substr((center - 1 - length) / 2, length);
}

string Solution::longestPalindrome(string A)
{

    return manachers(A, preprocess(A));
}
```