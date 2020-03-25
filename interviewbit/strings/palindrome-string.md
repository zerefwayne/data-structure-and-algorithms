## Approach 1: Two Pointer O(n) time O(1) space ACCEPTED

```cpp
int Solution::isPalindrome(string A)
{

    int n = A.length();

    int i = 0;
    int j = n - 1;

    while (!isalnum(A[i]) && i <= j)
    {
        i++;
    }
    while (!isalnum(A[j]) && i <= j)
    {
        j--;
    }

    while (i <= j)
    {
        if (isalnum(A[i]) && isalnum(A[j]))
        {
            if (tolower(A[i]) != tolower(A[j]))
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

        do
        {
            i++;
        } while (!isalnum(A[i]) && i <= j);
        do
        {
            j--;
        } while (!isalnum(A[j]) && i <= j);
    }

    return 1;
}
```