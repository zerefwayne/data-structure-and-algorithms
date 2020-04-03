#include <bits/stdc++.h>

using namespace std;

class Solution
{

    vector<pair<int, int>> movements{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

public:
    bool existUtil(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int idx, int rows, int cols, int x, int y)
    {

        visited[x][y] = true;

        if (idx == word.length())
        {
            return true;
        }

        for (auto &mvt : this->movements)
        {

            int dx = mvt.first;
            int dy = mvt.second;

            int nx = x + dx;
            int ny = y + dy;

            if (0 <= nx && nx < rows && ny >= 0 && ny < cols)
            {

                if (!visited[nx][ny])
                {

                    if (board[nx][ny] == word[idx])
                    {

                        if (existUtil(board, visited, word, idx + 1, rows, cols, nx, ny))
                        {
                            return true;
                        }
                    }
                }
            }
        }

        visited[x][y] = false;

        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        int rows = board.size();
        int cols = board[0].size();

        if (rows * cols < word.length())
        {
            return false;
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int idx = 0;

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {

                if (board[i][j] == word[idx])
                {

                    if (!visited[i][j])
                    {
                        if (existUtil(board, visited, word, idx + 1, rows, cols, i, j))
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};