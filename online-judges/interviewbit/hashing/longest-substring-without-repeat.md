```cpp
int Solution::lengthOfLongestSubstring(string A)
{
    unordered_map<char, int> index;
    int longest = 0;
    int start = 0;
    int i = 0;
    int len = A.length();

    while (i < len)
    {
        char c = A[i];

        if (index.find(c) == index.end())
        {
            index[c] = i;
            longest = max(longest, i - start + 1);
        }
        else
        {
            while (start <= index[c])
            {
                index.erase(A[start]);
                start++;
            }
            index[c] = i;
        }
        i++;
    }

    return longest;
}
```