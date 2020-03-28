## Approach 1 Stack Time O(nlogn) Space O(n)

```cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compareIntervals(Interval &a, Interval &b)
{

    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A)
{

    vector<Interval> intervals = A;

    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<Interval> res;

    if (A.size() == 0)
    {
        return res;
    }

    stack<Interval> travStack;

    for (auto interval : intervals)
    {

        if (travStack.empty() || interval.start > travStack.top().end)
        {
            travStack.push(interval);
        }
        else
        {
            Interval top = travStack.top();
            travStack.pop();
            Interval newInterval(min(top.start, interval.start), max(top.end, interval.end));
            travStack.push(newInterval);
        }
    }

    while (!travStack.empty())
    {
        res.emplace_back(travStack.top());
        travStack.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}
```