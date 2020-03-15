#include <bits/stdc++.h>

using namespace std;

int lcs_recursive(string a, string b)
{

    // Base case

    if (a == "" || b == "")
    {
        return 0;
    }

    // Last character matches

    int len_a = a.length();
    int len_b = b.length();

    if (a[len_a - 1] == b[len_b - 1])
    {
        return 1 + lcs_recursive(a.substr(0, len_a - 1), b.substr(0, len_b - 1));
    }

    return max(lcs_recursive(a, b.substr(0, len_b - 1)), lcs_recursive(a.substr(0, len_a - 1), b));
}

int main()
{

    string a;
    string b;
    cin >> a;
    cin >> b;

    int lcs = lcs_recursive(a, b);

    cout << lcs << '\n';

    return 0;
}