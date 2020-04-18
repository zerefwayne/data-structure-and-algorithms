```cpp
void subsetGenerator(vector<vector<int>> &res, int i, vector<int> &A, int n, vector<int> &curr)
{

    // Push as soon as the recursive function comes
    // When you need lexicographic ordering
    
    res.emplace_back(curr);

    if (i == n)
    {
        return;
    }

    for (int j = i; j < n; j++)
    {

        curr.push_back(A[j]);

        subsetGenerator(res, j + 1, A, n, curr);

        curr.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{

    vector<vector<int>> res;
    vector<int> curr;

    sort(A.begin(), A.end());

    subsetGenerator(res, 0, A, A.size(), curr);

    return res;
}
```