#include <bits/stdc++.h>

using namespace std;

class Solution
{

    vector<pair<int, int>> movements{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

public:
    int numIslands(vector<vector<char>> &grid)
    {

        if (grid.size() < 0)
        {
            return 0;
        }

        stack<pair<int, int>> visitStack;

        int rows = grid.size();
        int cols = grid[0].size();

        int numberOfIslands = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == '1')
                {

                    if (!visited[i][j])
                    {

                        numberOfIslands++;

                        visitStack.push(make_pair(i, j));

                        while (!visitStack.empty())
                        {

                            pair<int, int> top = visitStack.top();
                            visitStack.pop();

                            int x = top.first;
                            int y = top.second;

                            visited[x][y] = true;

                            for (auto &mvt : this->movements)
                            {

                                int dx = mvt.first;
                                int dy = mvt.second;

                                int nx = x + dx;
                                int ny = y + dy;

                                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
                                {

                                    if (grid[nx][ny] == '1' && !visited[nx][ny])
                                    {
                                        visitStack.push(make_pair(nx, ny));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return numberOfIslands;
    }
};