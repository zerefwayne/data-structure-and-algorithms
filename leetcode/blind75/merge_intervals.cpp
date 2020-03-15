#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

bool vectorComparator(const vector<int> &a, const vector<int> &b)
{

    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), vectorComparator);

        stack<pii> intervalStack;

        intervalStack.push(make_pair(intervals[0][0], intervals[0][1]));

        for (int i = 1; i < intervals.size(); i++)
        {

            int curr_0 = intervals[i][0];
            int curr_1 = intervals[i][1];

            int top_0 = intervalStack.top().first;
            int top_1 = intervalStack.top().second;

            if (top_1 - curr_0 >= 0)
            {
                pii new_pair = make_pair(top_0, max(curr_1, top_1));
                intervalStack.pop();
                intervalStack.push(new_pair);
            }
            else
            {
                intervalStack.push(make_pair(curr_0, curr_1));
            }
        }

        vector<vector<int>> res;

        while (!intervalStack.empty())
        {

            pii top = intervalStack.top();
            intervalStack.pop();
            vector<int> newrow{top.first, top.second};
            res.emplace_back(newrow);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};