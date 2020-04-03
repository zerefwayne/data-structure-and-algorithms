## Approach 1: Backtracking ACCEPTED

```cpp
void recurUtil(int A, int B, int curr, vector<int> &combination, vector<vector<int>> &combinations)
{

    if (combination.size() == B)
    {
        combinations.emplace_back(combination);
    }
    else
    {
        for (int i = curr; i <= A; i++)
        {
            combination.emplace_back(i);
            recurUtil(A, B, i + 1, combination, combinations);
            combination.pop_back();
        }
    }
}

vector<vector<int>> Solution::combine(int A, int B)
{
    vector<vector<int>> res;
    vector<int> combination;
    recurUtil(A, B, 1, combination, res);
    return res;
}
```