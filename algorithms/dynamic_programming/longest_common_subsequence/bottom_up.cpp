#include <bits/stdc++.h>

using namespace std;

int lcs_bottom_up(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();

    if (len_a == 0 || len_b == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1, 0));

    for (int i = 0; i <= len_a; i++)
    {

        for (int j = 0; j <= len_b; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[len_a][len_b];
}

int main()
{

    string a;
    string b;
    cin >> a;
    cin >> b;

    int lcs = lcs_bottom_up(a, b);

    cout << lcs << '\n';

    return 0;
}