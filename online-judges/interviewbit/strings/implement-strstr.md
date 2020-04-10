## Approach 1 KMP Algorithm

```cpp
vector<int> computeLPS(string str)
{

    int len = str.length();

    int j = 0;

    vector<int> lps(len, 0);

    for (int i = 1; i < len; i++)
    {

        while (j > 0 && str[i] != str[j])
        {
            j = lps[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

int kmp(string str, string pat, vector<int> lps)
{

    int i = 0;
    int j = 0;

    int str_len = str.length();
    int pat_len = pat.length();

    while (i < str_len)
    {

        if (str[i] == pat[j])
        {

            i++;
            j++;

            if (j == pat_len)
            {
                return i - j;
            }
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = lps[j - 1];
        }
    }

    return -1;
}

int Solution::strStr(const string A, const string B)
{

    string pattern = B;
    string str = A;

    if (pattern.size() == 0 || A.size() == 0)
    {
        return -1;
    }

    vector<int> lps = computeLPS(pattern);

    return kmp(str, pattern, lps);
}
```