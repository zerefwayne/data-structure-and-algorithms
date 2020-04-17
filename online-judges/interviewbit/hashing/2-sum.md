```cpp
vector<int> Solution::twoSum(const vector<int> &A, int B)
{
    // Maps value to index
    unordered_map<int, int> index;
    for (int i = 0; i < A.size(); i++)
    {
        if (index.find(B - A[i]) == index.end())
        {
            // pair doesn't exist
            index[A[i]] = i;
        }
        else
        {
            // pair exists

            int index1 = index[B - A[i]] + 1;
            int index2 = i + 1;
            return vector<int>{index1, index2};
        }
    }
    return vector<int>{};
}
```