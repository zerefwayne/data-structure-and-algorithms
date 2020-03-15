#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {

        int m = l + (r - l) / 2;

        if (nums[m] > nums[r])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << nums[l] << ' ' << l << '\n';

    return 0;
}