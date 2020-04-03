## Approach 1 Brute Force O(n^2)

```cpp
int Solution::maximumGap(const vector<int> &A)
{

    int i = 0;
    int j = A.size() - 1;
    int res = -1;

    for (int i = 0; i < A.size(); i++)
    {

        j = A.size() - 1;

        while (j >= i)
        {
            if (A[j] >= A[i])
            {
                res = max(res, j - i);
                break;
            }
            else
            {
                j--;
            }
        }
    }

    return res;
}
```

## Approach 2 Sorting Smart O(nlogn)

```cpp
int Solution::maximumGap(const vector<int> &A)
{

    vector<pair<int, int>> nums;

    for (int i = 0; i < A.size(); i++)
    {
        nums.emplace_back(make_pair(A[i], i));
    }
    
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    int n = A.size();
    int rmax = nums[n - 1].second;
    
    for (int i = n - 2; i >= 0; i--)
    {
        ans = max(ans, rmax - nums[i].second);
        rmax = max(rmax, nums[i].second);
    }
    
    return ans;
}
```