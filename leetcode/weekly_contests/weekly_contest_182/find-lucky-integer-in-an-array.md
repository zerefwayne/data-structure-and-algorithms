```cpp
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> umap;
        for (auto num : arr)
        {
            umap[num]++;
        }
        int res = -1;
        vector<pair<int, int>> A{umap.begin(), umap.end()};
        for (auto p : A)
        {
            if (p.first == p.second)
            {
                res = max(p.first, res);
            }
        }
        return res;
    }
};
```