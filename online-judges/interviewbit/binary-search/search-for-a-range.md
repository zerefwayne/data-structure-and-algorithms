```cpp
vector<int> Solution::searchRange(const vector<int> &A, int B)
{

    int n = A.size();
    int low = 0, high = n - 1;
    int mid = low + (high - low) / 2;
    vector<int> v(2);
    v[0] = -1;
    v[1] = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (A[mid] == B)
        {
            v[0] = mid;
            high = mid - 1;
        }
        else if (A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (v[0] == -1)
        return v;

    low = v[0];
    high = n - 1;

    while (low <= high)
    {

        mid = low + (high - low) / 2;
        if (A[mid] == B)
        {
            v[1] = mid;
            low = mid + 1;
        }
        else if (A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return v;
}
```