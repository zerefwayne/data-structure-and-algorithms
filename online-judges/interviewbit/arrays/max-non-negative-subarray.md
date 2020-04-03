## Approach 1 Sliding Window O(n)

```cpp
vector<int> Solution::maxset(vector<int> &A)
{
    int l = 0;
    int r = 0;
    int res_l = -1;
    int res_r = -1;
    long long int max_sum = INT_MIN;
    long long int curr = 0;

    while (r < A.size())
    {

        if (A[r] >= 0)
        {

            curr += A[r];

            if (curr > max_sum)
            {
                max_sum = curr;
                res_l = l;
                res_r = r;
            }
            else if (curr == max_sum)
            {

                int size = r - l + 1;
                int max_size = res_r - res_l + 1;

                if (size > max_size)
                {
                    res_l = l;
                    res_r = r;
                }
                else if (size == max_size && l < res_l)
                {
                    res_l = l;
                    res_r = r;
                }
            }
        }
        else
        {
            curr = 0;
            l = r + 1;
        }

        r++;
    }

    vector<int> res;

    if (res_l == -1)
    {
        return res;
    }

    for (int i = res_l; i <= res_r; i++)
    {
        res.emplace_back(A[i]);
    }

    return res;
}
```