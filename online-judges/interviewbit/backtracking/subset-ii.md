## Approach 1 Efficient technique



## Approach 2 Checking if curr exists in res Inefficient ACCEPTED

```cpp
void subset(vector<vector<int>> &res, vector<int> &curr, int start, vector<int> &A, int n)
{

    if (find(res.begin(), res.end(), curr) == res.end())
    {
        res.emplace_back(curr);
    }

    if (start == n)
    {
        return;
    }

    for (int i = start; i < n; i++)
    {

        curr.emplace_back(A[i]);

        subset(res, curr, i + 1, A, n);

        curr.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A)
{

    vector<vector<int>> res;
    vector<int> curr;

    sort(A.begin(), A.end());

    subset(res, curr, 0, A, A.size());

    return res;
}
```