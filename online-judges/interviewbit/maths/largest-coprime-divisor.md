## Approach 1 Check all factors till sqrt(A) O(sqrt n) TLE

```cpp
int Solution::cpFact(int A, int B)
{
    int res = INT_MIN;
    if (__gcd(A, B) == 1)
    {
        return A;
    }

    for (int i = 1; i * i <= A; i++)
    {
        if (A % i == 0)
        {

            if (__gcd(A / i, B) == 1)
            {
                res = max(res, A / i);
            }
            else if (__gcd(i, B) == 1)
            {
                res = max(res, i);
            }
        }
    }

    return res;
}
```

## Approach 2: Divide A by gcd until __gcd(A, B) is 1 AC

```cpp
int Solution::cpFact(int A, int B)
{
    int gcd = __gcd(A, B);
    while (gcd != 1)
    {
        A = A / res;
        gcd = __gcd(A, B);
    }

    return A;
}
```