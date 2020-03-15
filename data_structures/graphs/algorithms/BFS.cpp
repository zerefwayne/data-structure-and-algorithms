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

        cout << '\n';
    }

    void BFSRecursiveUtil()
    {
    }

    void BFSRecursive()
    {
    }

    void BFSIterative()
    {

        vector<bool> visited(V, false);
        queue<int> currentQueue;

        cout << "BFS Iterative: \n\n";

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == false)
            {

                currentQueue.push(i);

                while (!currentQueue.empty())
                {

                    int top = currentQueue.front();
                    cout << top << '\n';
                    currentQueue.pop();
                    visited[top] = true;

                    for (auto &conn : adj[top])
                    {

                        if (visited[conn] == false)
                        {
                            currentQueue.push(conn);
                        }
                    }
                }
            }
        }

        cout << '\n';
    }
};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 3, true);
    newGraph.addEdge(1, 4, false);
    newGraph.addEdge(0, 2, false);
    newGraph.addEdge(3, 4, true);

    newGraph.printGraph();

    newGraph.BFSIterative();

    return 0;
}