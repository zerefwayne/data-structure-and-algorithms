/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

User Task:
Since this is functional problem you don't have to worry about input, you just have to complete the function printPath()

Constraints:
1 <= T <= 10
2 <= n <= 10
0 <= m[][] <= 1

Example
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.
*/

class Action
{

public:
    int dx;
    int dy;
    char name;

    Action(int dx, int dy, char name)
    {
        this->dx = dx;
        this->dy = dy;
        this->name = name;
    }
};

class Graph
{

    int n;
    vector<vector<int>> maze;
    vector<Action> directions;
    vector<vector<bool>> visited;
    vector<string> possiblePaths;
    string current;

public:
    Graph(int n, int m[MAX][MAX])
    {
        this->n = n;
        this->resetGraph(n);
        this->setMaze(n, m);
    }

    void setMaze(int n, int m[MAX][MAX])
    {
        this->directions.clear();
        this->directions.emplace_back(Action(1, 0, 'D'));
        this->directions.emplace_back(Action(0, -1, 'L'));
        this->directions.emplace_back(Action(0, 1, 'R'));
        this->directions.emplace_back(Action(-1, 0, 'U'));

        this->maze.clear();
        this->maze.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->maze[i][j] = m[i][j];
            }
        }
    }

    void resetGraph(int n)
    {
        this->visited.clear();
        this->visited.resize(n, vector<bool>(n, false));
        possiblePaths.clear();
        current = "";
    }

    void searchMaze(int x, int y)
    {

        if (x == this->n - 1 && y == this->n - 1)
        {
            this->possiblePaths.emplace_back(this->current);
            return;
        }

        this->visited[x][y] = true;

        for (auto &dir : this->directions)
        {

            int newx = x + dir.dx;
            int newy = y + dir.dy;

            if (newx < 0 || newx > this->n - 1 || newy < 0 || newy > this->n - 1)
            {
                continue;
            }

            if (this->visited[newx][newy] == false && this->maze[newx][newy] == 1)
            {

                this->current.push_back(dir.name);
                this->searchMaze(newx, newy);
                this->current.pop_back();
            }
        }

        this->visited[x][y] = false;
    }

    void printPaths()
    {
        for (auto &path : this->possiblePaths)
        {
            cout << path << ' ';
        }
    }
};

vector<string> printPath(int m[MAX][MAX], int n)
{
    Graph g(n, m);
    g.searchMaze(0, 0);
    g.printPaths();
}