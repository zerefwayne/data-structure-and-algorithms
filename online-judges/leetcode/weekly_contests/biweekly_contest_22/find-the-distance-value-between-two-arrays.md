## Approach 1

```cpp
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        int distance = 0;
        int flag;

        for (auto num1 : arr1)
        {

            flag = 0;

            for (auto num2 : arr2)
            {

                if (abs(num1 - num2) <= d)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                distance++;
            }
        }

        return distance;
    }
};
```