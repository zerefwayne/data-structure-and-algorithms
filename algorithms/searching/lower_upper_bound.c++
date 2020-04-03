#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int el)
{

    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int m;

    while (l <= r)
    {

        m = l + (r - l) / 2;

        if (arr[m] == el)
        {
            int idx = m;

            while (idx > 0 && arr[idx] == arr[idx - 1])
            {
                idx--;
            }

            return idx;
        }
        else if (arr[m] > el)
        {

            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return m;
}

int upperBound(vector<int> arr, int el)
{

    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int m;

    while (l <= r)
    {

        m = l + (r - l) / 2;

        if (arr[m] == el)
        {
            int idx = m;

            while (idx < n-1 && arr[idx] == arr[idx + 1])
            {
                idx++;
            }

            return idx+1;
        }
        else if (arr[m] > el)
        {

            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return m;
}

int main()
{

    vector<int> arr{1, 2, 3, 6, 6, 6, 6, 6, 6, 6, 7, 11, 13, 15};

    int lb = lowerBound(arr, 0);
    int ub = upperBound(arr, 6);

    cout << lb << ' ' << arr[lb] << '\n';
    cout << ub << ' ' << arr[ub] << '\n';

    return 0;
}