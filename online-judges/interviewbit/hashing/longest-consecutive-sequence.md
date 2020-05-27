```cpp
int Solution::longestConsecutive(const vector<int> &A)
{

    unordered_set<int> starts;
    unordered_map<int, int> status;

    for (const auto &num : A)
    {

        if (status.find(num) != status.end())
        {
            continue;
        }

        int next = num + 1;
        int prev = num - 1;

        bool isNext = status.find(next) != status.end();
        bool isPrev = status.find(prev) != status.end();

        if (isNext && isPrev)
        {

            if (status[next] == 0)
            {
                status[next] = -1;
            }
            else
            {
                starts.erase(next);
                status[next] = 2;
            }

            if (status[prev] == 0)
            {
                status[prev] = +1;
                starts.insert(prev);
            }
            else
            {
                status[prev] = 2;
            }

            status[num] = 2;
        }
        else if (isNext)
        {

            if (status[next] == 0)
            {
                status[next] = -1;
            }
            else
            {
                starts.erase(next);
                status[next] = 2;
            }

            status[num] = 1;
            starts.insert(num);
        }
        else if (isPrev)
        {

            if (status[prev] == 0)
            {
                status[prev] = +1;
                starts.insert(prev);
            }
            else
            {
                status[prev] = 2;
            }

            status[num] = -1;
        }
        else
        {

            status[num] = 0;
        }
    }

    int longest = 1;
    int current = 0;

    for (auto it = starts.begin(); it != starts.end(); it++)
    {

        int start = *it;

        while (status.find(start) != status.end())
        {
            current++;
            longest = max(longest, current);
            start++;
        }

        current = 0;
    }

    return longest;
}
```