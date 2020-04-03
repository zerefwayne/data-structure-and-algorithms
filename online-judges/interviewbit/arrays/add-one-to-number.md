## Approach 1 time O(n) space O(n) uses extra array

```cpp
vector<int> Solution::plusOne(vector<int> &A)
{

    int zeros = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            zeros++;
        }
        else
        {
            break;
        }
    }

    if (zeros == A.size())
    {
        return vector<int>{1};
    }

    reverse(A.begin(), A.end());

    int carry = 1;

    vector<int> incremented;

    for (int i = 0; i < A.size() - zeros; i++)
    {

        int digit = carry + A[i];
        if (digit > 9)
        {
            carry = 1;
            incremented.emplace_back(digit - 9);
        }
        else
        {
            carry = 0;
            incremented.emplace_back(digit);
        }
    }

    if (carry == 1)
    {
        incremented.emplace_back(1);
    }

    reverse(incremented.begin(), incremented.end());

    return incremented;
}
```