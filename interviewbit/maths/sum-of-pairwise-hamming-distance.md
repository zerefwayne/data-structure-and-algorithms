## Approach 1 O(n^2) Time Limit Exceeded

```cpp
int hamming(int A, int B)
{

    int res = 0;

    while (A > 0 || B > 0)
    {

        if (A % 2 != B % 2)
        {
            res++;
        }

        A /= 2;
        B /= 2;
    }

    return res;
}

int Solution::hammingDistance(const vector<int> &A)
{
    int res = 0;
    int mod = 1000000007;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            res = (res + ((hamming(A[i], A[j]) % mod) * 2) % mod) % mod;
        }
    }
    return res % mod;
}
```

## Approach 2 O(n) Accepted Smart Bitwise counting

```cpp
int Solution::hammingDistance(const vector<int> &A)
{
    int res = 0;
    int mod = 1000000007;

    for (int i = 0; i < 32; i++)
    {

        int count = 0;

        // count represents number of set ith bits

        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] & (1 << i))
            {
                count++;
            }
        }

        // there will be count*(n-count) pairs with different bits and *2 because they repeat

        res = (res + (count % mod) * ((A.size() - count) % mod) * 2) % mod;
    }
    return res % mod;
}
```