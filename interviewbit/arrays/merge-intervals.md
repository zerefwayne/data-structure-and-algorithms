## Approach 1 Stack time O(nlogn) space O(n) 

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

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{

    if (intervals.size() == 0)
    {
        return vector<Interval>{newInterval};
    }

    if (newInterval.start > newInterval.end)
    {
        newInterval = Interval(newInterval.end, newInterval.start);
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int left = newInterval.start;
    int right = newInterval.end;

    if (left <= intervals[0].start && right >= intervals.back().end)
    {
        return vector<Interval>{newInterval};
    }

    int li = -1;
    int ri = -1;

    for (int i = 0; i < intervals.size(); i++)
    {

        int lb = intervals[i].start;
        int rb = intervals[i].end;

        if (li == -1)
        {
            if (lb <= left && left <= rb)
            {
                li = i;
            }
        }

        if (ri == -1)
        {
            if (lb <= right && right <= rb)
            {
                ri = i;
            }
        }

        if (li != -1 && ri != -1)
        {
            break;
        }
    }

    if (li == -1)
    {
        intervals.emplace_back(left, max(intervals[ri].end, right));
    }
    else if (ri == -1)
    {
        intervals.emplace_back(min(intervals[li].start, left), right);
    }
    else
    {
        intervals.emplace_back(newInterval);
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

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

    vector<Interval> res;

    while (!travStack.empty())
    {
        res.emplace_back(travStack.top());
        travStack.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}
```