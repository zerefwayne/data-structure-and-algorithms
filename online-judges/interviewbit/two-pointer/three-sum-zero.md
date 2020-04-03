## Approach 1: Two Pointer O(n^2) time O(1) space

```cpp
vector<vector<int>> Solution::threeSum(vector<int> &A)
{

    sort(A.begin(), A.end());

    vector<vector<int>> res;

    int l = 0, m, r, sum, n = A.size();

    while (l < n - 2)
    {

        m = l + 1;
        r = n - 1;

        while (m < r)
        {

            sum = A[l] + A[m] + A[r];

            if (sum == 0)
            {
                res.emplace_back(vector<int>{A[l], A[m], A[r]});
                do
                {
                    m++;
                } while (m < r && A[m] == A[m - 1]);
                do
                {
                    r--;
                } while (m < r && A[r] == A[r + 1]);
            }
            else if (sum < 0)
            {
                do
                {
                    m++;
                } while (m < r && A[m] == A[m - 1]);
            }
            else
            {
                do
                {
                    r--;
                } while (m < r && A[r] == A[r + 1]);
            }
        }

        do
        {
            l++;
        } while (l < n && A[l] == A[l - 1]);
    }

    return res;
}
```