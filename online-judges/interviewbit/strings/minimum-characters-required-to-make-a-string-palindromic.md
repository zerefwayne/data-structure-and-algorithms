## Approach 1 Delete Last characters and check if string is palindrome ACCEPTED O(n^2)

```cpp
bool isPalindrome(string str)
{

    if (str.length() < 2)
    {
        return true;
    }

    int l = 0;
    int r = str.length() - 1;

    while (l <= r)
    {

        if (str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

int Solution::solve(string A)
{

    int n = A.length();

    while (A != "")
    {
        if (isPalindrome(A))
        {
            return n - A.length();
        }
        else
        {
            A.erase(A.begin() + A.length() - 1);
        }
    }

    return n;
}
```