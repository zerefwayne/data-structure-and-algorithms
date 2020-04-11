```cpp
int Solution::searchInsert(vector<int> &A, int B)
{

    // Implementation of lower_bound function of C++ STL

    vector<int> arr = A;
    int el = B;

    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int m;

    while (l <= r)
    {

        m = l + (r - l) / 2;

        if (arr[m] == el)
        {
            return m;
        }
        else if (arr[m] > el)
        {

            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return l;
}
```