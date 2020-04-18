## Approach 1 Swap the elements to start position in loop

```cpp
class Solution
{
public:
    void permute(vector<int> &num, int start, vector<vector<int>> &result)
    {
        if (start == num.size() - 1)
        {
            result.push_back(num);
            return;
        }
        for (int i = start; i < num.size(); i++)
        {
            swap(num[start], num[i]);
            permute(num, start + 1, result);
            swap(num[start], num[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &num)
    {
        vector<vector<int>> result;
        if (num.size() == 0)
            return result;
        sort(num.begin(), num.end());
        permute(num, 0, result);
        return result;
    }
};
```

## Approach 2 Remove element and add element from actual List

```cpp
void generatePermutation(vector<vector<int>> &res, vector<int> &curr, vector<int> &A, int n)
{

    if (curr.size() == n)
    {
        res.push_back(curr);
        return;
    }

    for (int j = 0; j < A.size(); j++)
    {
        int t = A[j];

        A.erase(A.begin() + j);

        curr.emplace_back(t);

        generatePermutation(res, curr, A, n);

        curr.pop_back();

        A.insert(A.begin() + j, t);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A)
{

    vector<vector<int>> res;
    vector<int> curr;

    generatePermutation(res, curr, A, A.size());

    return res;
}
```