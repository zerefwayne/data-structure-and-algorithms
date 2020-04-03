## Approach 1: Two Pointer Technique

```cpp
vector<int> Solution::flip(string A)
{

    int i_res = -1;
    int j_res = -1;
    int max_array = INT_MIN;

    int i = 0;
    int j = 0;
    int n = A.length();
    int count = 0;

    while (i < n)
    {

        if (A[i] == '1')
        {
            count--;
        }
        else
        {
            count++;
        }

        if (count > 0 && count > max_array)
        {
            max_array = count;
            i_res = i;
            j_res = j;
        }

        if (count < 0)
        {
            j = i + 1;
            count = 0;
        }

        i++;
    }

    if (i_res == -1)
    {
        return vector<int>();
    }

    return vector<int>{j_res + 1, i_res + 1};
}
```