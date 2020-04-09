## Approach 1 2 Pass Find pivot then search

```cpp
int findPivot(const vector<int> &A)
{

    int l = 0;
    int h = A.size() - 1;

    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (A[mid] > A[h])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }

    return l;
}

int binarySearch(const vector<int> A, int pivot, int B)
{

    int l = 0;
    int r = A.size() - 1;

    while (l <= r)
    {

        int m = l + (r - l) / 2;
        int real_m = (m + pivot) % A.size();

        if (A[real_m] == B)
        {
            return real_m;
        }
        else if (A[real_m] < B)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return -1;
}

int Solution::search(const vector<int> &A, int B)
{
    int n = A.size();
    int pivot = findPivot(A);
    return binarySearch(A, pivot, B);
}
```