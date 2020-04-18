```cpp
void generate(vector<vector<int>> &res, vector<int> &curr, vector<int> &A, int start, int remainingSum)
{

    if (remainingSum <= 0)
    {
        if (remainingSum == 0)
        {
            res.emplace_back(curr);
        }
        return;
    }

    for (int i = start; i < A.size(); i++)
    {

        // To handle duplications
        if (i > start)
        {
            if (A[i] == A[i - 1])
            {
                continue;
            }
        }

        if (remainingSum >= A[i])
        {
            curr.emplace_back(A[i]);
            generate(res, curr, A, i+1, remainingSum - A[i]);
            curr.pop_back();
        }
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{

    vector<vector<int>> res;
    vector<int> curr;

    sort(A.begin(), A.end());
    generate(res, curr, A, 0, B);
    return res;
}
```