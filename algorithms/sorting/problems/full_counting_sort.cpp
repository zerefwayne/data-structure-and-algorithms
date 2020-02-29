/*
    https://www.hackerrank.com/challenges/countingsort4/problem

    The Full Counting Sort

    In this challenge you need to print the string that accompanies each integer in a list sorted by the integers. If two strings are associated with the same integer, they must be printed in their original order so your sorting algorithm should be stable. There is one other twist. The first half of the strings encountered in the inputs are to be replaced with the character "-".

    Insertion Sort and the simple version of Quicksort are stable, but the faster in-place version of Quicksort is not since it scrambles around elements while sorting.

    In this challenge, you will use counting sort to sort a list while keeping the order of the strings preserved.

*/

#include <bits/stdc++.h>

using namespace std;

void countSort(vector<vector<string>> arr)
{

    vector<int> numbers;

    for (auto &x : arr)
    {
        numbers.emplace_back(stoi(x[0]));
    }

    int max = *max_element(numbers.begin(), numbers.end()) + 1;

    vector<int> count(max, 0);

    for (auto &num : numbers)
    {
        count[num]++;
    }

    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = max - 1; i > 0; i--)
    {
        count[i] = count[i - 1];
    }

    count[0] = 0;

    vector<string> ans(arr.size(), "");

    for (int i = 0; i < arr.size(); i++)
    {
        int num = stoi(arr[i][0]);
        string str = arr[i][1];

        int index = count[num];
        count[num]++;

        if (i < arr.size() / 2)
        {
            ans[index] = "-";
        }
        else
        {
            ans[index] = str;
        }
    }

    for (auto &str : ans)
    {
        cout << str << ' ';
    }

    cout << '\n';
}