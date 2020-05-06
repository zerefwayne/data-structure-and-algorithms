```cpp
bool isPalindrome(string &str, int l, int r)
{
    while (l <= r)
    {
        if (str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void recurse(string &str, int l, vector<string> &curr, vector<vector<string>> &all)
{

    int len = str.length();

    if (l == len)
    {
        all.emplace_back(curr);
        return;
    }

    for (int i = l; i < len; i++)
    {
        if (isPalindrome(str, l, i))
        {
            curr.emplace_back(str.substr(l, i - l + 1));
            recurse(str, i + 1, curr, all);
            curr.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A)
{

    vector<vector<string>> ret;
    vector<string> curr;

    recurse(A, 0, curr, ret);

    return ret;
}
```