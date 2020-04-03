/*
    Ehab has an array a of length n. He has just enough free time to make a new array consisting of n copies of the old array, written back-to-back. What will be the length of the new array's longest increasing subsequence?

    A sequence a is a subsequence of an array b if a can be obtained from b by deletion of several (possibly, zero or all) elements. The longest increasing subsequence of an array is the longest subsequence such that its elements are ordered in strictly increasing order.

    Input
    The first line contains an integer t — the number of test cases you need to solve. The description of the test cases follows.

    The first line of each test case contains an integer n (1≤n≤105) — the number of elements in the array a.

    The second line contains n space-separated integers a1, a2, …, an (1≤ai≤109) — the elements of the array a.

    The sum of n across the test cases doesn't exceed 105.

    Output
    For each testcase, output the length of the longest increasing subsequence of a if you concatenate it to itself n times.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        vector<int> nums(n);
        int min_element = INT_MAX;
        int min_index = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] < min_element)
            {
                min_element = nums[i];
                min_index = i;
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {

            if (i == min_index)
            {
                count++;
                continue;
            }

            if (nums[i] > min_element)
            {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}