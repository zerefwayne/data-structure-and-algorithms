## Approach 1 Iterative

```cpp
int gcdUtil(int A, int B)
{
    int tmp;

    while (B > 0)
    {
        tmp = A;
        A = B;
        B = tmp % B;
    }

    return A;
}

int Solution::gcd(int A, int B)
{
    return gcdUtil(A, B);
}
```