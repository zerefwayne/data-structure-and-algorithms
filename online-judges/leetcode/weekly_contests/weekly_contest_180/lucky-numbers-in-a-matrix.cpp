#include <bits/stdc++.h>

using namespace std;

/*
    Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
    A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

    Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    Output: [15]
    Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column

    Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    Output: [12]
    Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
*/

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {

        set<int> columns;

        int m = matrix.size();
        int n = matrix[0].size();

        set<int> minimums;

        for (int i = 0; i < m; i++)
        {
            int min_index = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            columns.insert(min_index);
            minimums.insert(matrix[i][min_index]);
        }

        vector<int> res;

        for (auto &c : columns)
        {

            int max_element = INT_MIN;

            for (int i = 0; i < m; i++)
            {
                max_element = max(max_element, matrix[i][c]);
            }

            if (minimums.find(max_element) != minimums.end())
            {
                res.emplace_back(max_element);
            }
        }

        return res;
    }
};