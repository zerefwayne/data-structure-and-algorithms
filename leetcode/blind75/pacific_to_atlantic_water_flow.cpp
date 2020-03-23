#include <bits/stdc++.h>

using namespace std;

class Solution
{

    vector<vector<int>> matrix;
    vector<vector<int>> visited;
    int m;
    int n;
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    // -1 Atlantic -2 Pacific

    void beachToCellDFS(int x, int y, int code, vector<vector<int>> &res)
    {

        if (this->visited[x][y] == -1 && code == -2)
        {
            res.emplace_back(vector<int>{x, y});
        }

        this->visited[x][y] = code;

        for (auto &dir : this->dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < this->m && ny >= 0 && ny < this->n && this->visited[nx][ny] != code && this->matrix[nx][ny] >= this->matrix[x][y])
            {
                this->beachToCellDFS(nx, ny, code, res);
            }
        }
    }

    vector<vector<int>> beachToCell(vector<vector<int>> &matrix)
    {

        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return vector<vector<int>>{};
        }

        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->visited = vector<vector<int>>(m, vector<int>(n));
        vector<vector<int>> res;

        for (int col = 0; col < n; col++)
        {
            this->beachToCellDFS(0, col, -1, res);
        }

        for (int row = 0; row < m; row++)
        {
            this->beachToCellDFS(row, 0, -1, res);
        }

        for (int col = 0; col < n; col++)
        {
            this->beachToCellDFS(m - 1, col, -2, res);
        }

        for (int row = 0; row < m; row++)
        {
            this->beachToCellDFS(row, n - 1, -2, res);
        }

        return res;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        return this->beachToCell(matrix);
    }
};