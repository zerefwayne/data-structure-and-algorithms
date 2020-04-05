```cpp
class Solution
{
public:
    int numSteps(string s)
    {

        int steps = 0;
        int l = s.length();

        for (int i = l - 1; i >= 0;)
        {

            if (s[i] == '0')
            {
                steps++;
                i--;
            }
            else if (s[i] == '1')
            {

                if (i == 0)
                {
                    break;
                }

                int j = i;
                int n = 0;

                while (j >= 0 && s[j] == '1')
                {
                    n++;
                    j--;
                }

                steps += n + 1;

                if (j == -1)
                {
                    break;
                }
                else
                {
                    i = j;
                    s[i] = '1';
                }
            }
        }

        return steps;
    }
};
```