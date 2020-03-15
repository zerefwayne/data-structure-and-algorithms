#include <bits/stdc++.h>

using namespace std;

vector<int> buildLPS(string str)
{
    int len = str.length();

    vector<int> lps(len, 0);

    int j = 0;

    for (int i = 1; i < len; i++)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = lps[j - 1];
        }
        if (str[j] == str[i])
        {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

int kmp(string str, string pat)
{

    if (pat.length() < 0)
    {
        return 0;
    }

    vector<int> prefix = buildLPS(str);

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
            j = prefix[j - 1];
        }
    }

    return -1;
}

int main()
{

    string str = "acacabacacabacacac";
    string pat = "bacaca";

    int ans = kmp(str, pat);

    if (ans != -1)
    {

        cout << pat << " exists in " << str << " at " << ans << '\n';
    }
    else
    {

        cout << pat << " doesn't exist in " << str << '\n';
    }

    return 0;
}