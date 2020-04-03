#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> &a, const pair<int, int> &b)
{

    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int main()
{

    int n;
    cin >> n;
    int x = 0;

    vector<pair<int, int>> arr(n);

    int t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr[i] = make_pair(t, i + 1);
    }

    sort(arr.begin(), arr.end(), comparator);

    int shots = 0;
    int dur;
    vector<int> order;

    for (int i = 0; i < n; i++)
    {
        shots += arr[i].first * i + 1;
        order.emplace_back(arr[i].second);
    }

    cout << shots << '\n';
    for (auto s : order)
    {
        cout << s << ' ';
    }
    cout << '\n';

    return 0;
}