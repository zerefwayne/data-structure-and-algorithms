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