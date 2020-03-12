#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {

        int count = 0;
        int largest = 0;
        int moments = 0;

        for (int i = 0; i < light.size(); i++)
        {
            count++;
            largest = max(largest, light[i]);
            if (largest == count)
            {
                moments++;
            }
        }

        return moments;
    }
};