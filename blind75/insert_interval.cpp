#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

bool vecComparator(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> res;

        if (intervals.size() < 1)
        {
            return res;
        }

        sort(intervals.begin(), intervals.end(), vecComparator);

        vector<int> first = intervals[0];
        vector<int> last = *(intervals.end() - 1);

        if (newInterval[1] < first[0])
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        if (newInterval[0] > last[1])
        {
            intervals.emplace_back(newInterval);
            return intervals;
        }

        if (newInterval[0] <= first[0] && newInterval[1] >= last[1])
        {
            res.emplace_back(newInterval);
            return res;
        }

        bool liesBetween = false;

        for (int i = 0; i < intervals.size() - 1; i++)
        {

            if (intervals[i][1] < newInterval[0] && newInterval[1] < intervals[i + 1][0])
            {
                liesBetween = true;
                break;
            }
        }

        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end(), vecComparator);

        if (liesBetween)
        {
            return intervals;
        }
        else
        {

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
    }
};