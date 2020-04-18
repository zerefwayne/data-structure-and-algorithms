```cpp
bool lessThan(vector<int> a, vector<int> b)
{

    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }

    return false;
}

vector<int> Solution::equal(vector<int> &A)
{

    unordered_map<int, pair<int, int>> sums;
    vector<int> res(4, INT_MAX);

    int a = 0;
    int b = 0;
    bool flag = false;

    for (int i = 0; i < A.size(); i++)
    {

        for (int j = i + 1; j < A.size(); j++)
        {

            int sum = A[i] + A[j];

            if (sums.find(sum) == sums.end())
            {

                sums[sum] = make_pair(i, j);
            }
            else
            {

                pair<int, int> loc = sums[sum];

                if (loc.first < i && loc.second != i && loc.second != j)
                {

                    vector<int> vec{loc.first, loc.second, i, j};

                    if (lessThan(vec, res))
                    {
                        flag = true;
                        res = vec;
                    }
                }
            }
        }
    }

    if (flag)
    {
        return res;
    }
    else
    {
        return vector<int>{};
    }
}
```