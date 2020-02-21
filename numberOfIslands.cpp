#include <bits/stdc++.h>

using namespace std;

class Graph
{

public:
    vector<vector<int>> adj;
    int V;

    Graph(int _V)
    {
        V = _V;
        adj.resize(V);
    }

    void addEdge(int src, int dest, bool isUnidirectional)
    {

        if (src >= 0 && src < V && dest >= 0 && dest < V && dest != src)
        {

            if (find(adj[src].begin(), adj[src].end(), dest) == adj[src].end())
            {
                adj[src].emplace_back(dest);
            }

            if (isUnidirectional == false)
            {

                if (find(adj[dest].begin(), adj[dest].end(), src) == adj[dest].end())
                {
                    adj[dest].emplace_back(src);
                }
            }
        }
    }

    void printGraph()
    {

        for (int i = 0; i < V; i++)
        {

            cout << i << "->";

            for (auto &vertex : adj[i])
            {

                cout << vertex << "->";
            }

            cout << '\n';
        }
    }

    void findNumberOfIslands()
    {

        int numberOfIslands = 0;

        stack<int> travStack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == false)
            {

                numberOfIslands++;

                travStack.emplace(i);

                while (!travStack.empty())
                {

                    int top = travStack.top();
                    visited[top] = true;
                    travStack.pop();

                    for (auto &child : adj[top])
                    {
                        if (visited[child] == false)
                        {
                            travStack.emplace(child);
                        }
                    }
                }
            }
        }

        cout << "Number of islands: " << numberOfIslands << '\n'
             << '\n';
    }
};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 3, true);
    newGraph.addEdge(1, 4, false);
    newGraph.addEdge(0, 3, false);

    newGraph.printGraph();

    newGraph.findNumberOfIslands();

    return 0;
}