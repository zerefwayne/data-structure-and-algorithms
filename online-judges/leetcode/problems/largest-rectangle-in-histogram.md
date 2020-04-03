## Approach 1: Stack Approach time O(n) Space O(n)

```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int area = 0;
        int max_area = 0;
        int i = 0;
        stack<int> prevBuildings;

        for (i = 0; i < heights.size();)
        {
            if (prevBuildings.empty() || heights[i] >= heights[prevBuildings.top()])
            {
                prevBuildings.push(i++);
            }
            else
            {
                int top = prevBuildings.top();
                prevBuildings.pop();
                area = heights[top] * (prevBuildings.empty() ? i : (i - prevBuildings.top() - 1));
                max_area = max(max_area, area);
            }
        }

        while (!prevBuildings.empty())
        {
            int top = prevBuildings.top();
            prevBuildings.pop();
            area = heights[top] * (prevBuildings.empty() ? i : i - prevBuildings.top() - 1);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
```