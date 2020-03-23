#include <bits/stdc++.h>

using namespace std;

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int rooms = 0;
    int n = arrive.size();

    int ai = 0;
    int di = 0;

    while (ai < n && di < n)
    {

        if (arrive[ai] < depart[di])
        {
            ai++;
            rooms++;

            if (rooms > K)
                return false;
        }
        else
        {
            di++;
            rooms--;
        }
    }

    return true;
}