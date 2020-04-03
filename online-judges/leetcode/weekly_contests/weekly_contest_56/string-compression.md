[Question Link](https://leetcode.com/contest/leetcode-weekly-contest-56/problems/string-compression/)

## Approach 1 O(n) ACCEPTED

```cpp
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int size = 1;
        char curr = chars[0];
        int i = 1;
        int n = chars.size();
        int update = 0;

        for (int i = 1; i < n; i++)
        {
            if (chars[i] != curr)
            {
                if (size == 1)
                {
                    chars[update++] = curr;
                    curr = chars[i];
                    size = 1;
                }
                else
                {
                    chars[update++] = curr;

                    string size_str = to_string(size);

                    for (auto c : size_str)
                    {
                        chars[update++] = c;
                    }

                    curr = chars[i];
                    size = 1;
                }
            }
            else
            {
                size++;
            }
        }

        if (size == 1)
        {
            chars[update++] = curr;
        }
        else
        {
            chars[update++] = curr;
            string size_str = to_string(size);

            for (auto c : size_str)
            {
                chars[update++] = c;
            }
        }

        return update;
    }
};
```