## Approach 1: Simple permutation formula and modulo

```cpp
#define lli long long int
#define mod 1000003

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : (factorial(n - 1) % mod * n % mod) % mod;
}

int smallerToRight(string A, int i)
{

    int count = 0;

    for (int j = i + 1; j < A.length(); j++)
    {
        if (A[j] < A[i])
        {
            count++;
        }
    }

    return count;
}

int Solution::findRank(string A)
{

    int n = A.length();

    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        idx = (idx % mod + (smallerToRight(A, i) * factorial(n - i - 1)) % mod) % mod;
    }

    return idx % mod;
}
```

## Approach 2: Precompute array and delete once the character is selected

```cpp
#define lli long long int
#define mod 1000003

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : (factorial(n - 1) % mod * n % mod) % mod;
}

int Solution::findRank(string A)
{

    int n = A.length();

    vector<char> b{A.begin(), A.end()};

    sort(b.begin(), b.end());

    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        int j = find(b.begin(), b.end(), A[i]) - b.begin();
        idx = (idx + ((j % mod) * (factorial(n - i - 1) % mod)) % mod) % mod;
        b.erase(b.begin() + j);
    }

    return idx % mod;
}
```