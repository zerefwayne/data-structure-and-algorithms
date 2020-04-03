/*

    Problem Link: https://cses.fi/problemset/task/1192
    Name: Counting Rooms
    Topic: Graph Algorithms

    You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

    Input

    The first input line has two integers n and m: the height and width of the map.

    Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

    Output

    Print one integer: the number of rooms.

    Constraints
    1≤n,m≤1000
    Example

    Input:
    5 8
    ########
    #..#...#
    ####.#.#
    #..#...#
    ########

    Output:
    3

*/

/*
    Approach: Calculate the number of 4 Connected components, DFS
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{

    vector<vector<char>> adj;
    int rows;
    int cols;
    vector<pair<int, int>> movements;

public:
    Graph(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        this->adj.resize(rows, vector<char>(cols));

        this->movements.emplace_back(make_pair(0, 1));
        this->movements.emplace_back(make_pair(1, 0));
        this->movements.emplace_back(make_pair(0, -1));
        this->movements.emplace_back(make_pair(-1, 0));
    }

    void inputFloorMap()
    {

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                char cell;
                cin >> cell;
                this->adj[i][j] = cell;
            }
        }
    }

    void countRoomsUtil(int x, int y, vector<vector<bool>> &visited)
    {

        visited[x][y] = true;

        for (auto &movement : this->movements)
        {

            int new_x = x + movement.first;
            int new_y = y + movement.second;

            if (new_x >= 0 && new_x < this->rows && new_y >= 0 && new_y < this->cols)
            {

                if (this->adj[new_x][new_y] == '.')
                {

                    if (visited[new_x][new_y] == false)
                    {
                        countRoomsUtil(new_x, new_y, visited);
                    }
                }
            }
        }
    }

    int countRooms()
    {

        int rooms = 0;
        vector<vector<bool>> visited(this->rows, vector<bool>(this->cols));

        for (int i = 0; i < this->rows; i++)
        {

            for (int j = 0; j < this->cols; j++)
            {

                if (this->adj[i][j] == '.')
                {

                    if (!visited[i][j])
                    {

                        this->countRoomsUtil(i, j, visited);
                        rooms++;
                    }
                }
            }
        }

        return rooms;
    }
};

int main()
{

    int rows, cols;
    cin >> rows;
    cin >> cols;

    Graph graph(rows, cols);

    graph.inputFloorMap();

    cout << graph.countRooms() << '\n';
}