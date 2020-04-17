```cpp
vector<vector<int>> Solution::anagrams(const vector<string> &A)
{

    unordered_map<string, int> idx;
    vector<vector<int>> res;

    for (int i = 0; i < A.size(); i++)
    {

        // Since A[i] is constant we copy the value to temp variable
        string temp = A[i];

        // Sort the string
        sort(temp.begin(), temp.end());

        if (idx.find(temp) != idx.end())
        {
            // Sorted string exists in the map
            // idx[temp] will give the index in the res
            res[idx[temp]].emplace_back(i + 1);
        }
        else
        {
            // Sorted string doesn't exist

            // Index of string is stored
            idx[temp] = res.size();
            // A new vector is pushed in the res vector
            res.emplace_back(vector<int>{i + 1});
        }
    }

    return res;
}
```