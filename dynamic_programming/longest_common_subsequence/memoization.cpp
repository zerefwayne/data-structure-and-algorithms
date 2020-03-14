#include <bits/stdc++.h>

using namespace std;

int lcs_memoization(string a, string b, unordered_map<string, int> &cache)
{

    if (a == "" || b == "")
    {
        return 0;
    }

    string key = a + "," + b;

    if (cache.find(key) != cache.end())
    {
        return cache[key];
    }

    int len_a = a.length();
    int len_b = b.length();

    int val;

    if (a[len_a - 1] == b[len_b - 1])
    {
        val = 1 + lcs_memoization(a.substr(0, len_a - 1), b.substr(0, len_b - 1), cache);
    }
    else
    {
        val = max(lcs_memoization(a, b.substr(0, len_b - 1), cache), lcs_memoization(a.substr(0, len_a - 1), b, cache));
    }

    cache[key] = val;

    return val;
}

int main()
{

    string a;
    string b;
    cin >> a;
    cin >> b;

    unordered_map<string, int> cache;

    int lcs = lcs_memoization(a, b, cache);

    cout << lcs << '\n';

    return 0;
}