```cpp
vector<int> Solution::lszero(vector<int> &A)
{

    // sum -> earliest_index
    unordered_map<int, int> at;

    // initial
    at[0] = -1;
    int sum = 0;
    vector<int> longest;

    for (int i = 0; i < A.size(); i++)
    {

        sum += A[i];

        if (at.find(sum) == at.end())
        {
            at[sum] = i;
        }
        else
        {

            int idx = at[sum];

            int size = i - idx;

            if (size > longest.size())
            {

                vector<int> new_vec(A.begin() + idx + 1, A.begin() + idx + 1 + size);
                longest = new_vec;
            }
        }
    }

    return longest;
}
```