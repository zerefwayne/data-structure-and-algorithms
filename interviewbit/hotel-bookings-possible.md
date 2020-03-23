## Approach 1: Event Creation and sorting O(nlogn) time O(2n) space

```cpp
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{

    vector<pair<int, int>> events;

    for (int i = 0; i < arrive.size(); i++)
    {
        events.emplace_back(make_pair(arrive[i], 1));
        events.emplace_back(make_pair(depart[i], -1));
    }

    sort(events.begin(), events.end());

    int rooms = 0;

    for (auto &event : events)
    {
        rooms += event.second;
        if (rooms > K)
        {
            return false;
        }
    }

    return true;
}
```

## Approach 2: Two Pointer Technique O(nlogn) time O(1) space

```cpp
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
```

### Concepts: Array, Maximum Overlap of Intervals, Two Pointer Technique