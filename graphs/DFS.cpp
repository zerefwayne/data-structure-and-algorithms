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

    void DFSRecursiveUtil(int currentNode, unordered_set<int> &visited)
    {

        cout << currentNode << '\n';
        visited.insert(currentNode);

        for (auto &conn : adj[currentNode])
        {
            if (visited.find(conn) == visited.end())
            {
                DFSRecursiveUtil(conn, visited);
            }
        }
    }

    void DFSRecursive()
    {

        cout << "DFS:\n\n";

        unordered_set<int> visited;

        for (int i = 0; i < V; i++)
        {

            if (visited.find(i) == visited.end())
            {
                DFSRecursiveUtil(i, visited);
            }
        }

        cout << "\n";
    }

    void DFSIterative()
    {

        vector<bool> visited(V, false);
        stack<int> currentStack;

        cout << "DFS Iterative:\n\n";

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == false)
            {

                currentStack.push(i);

                while (!currentStack.empty())
                {

                    int top = currentStack.top();
                    currentStack.pop();
                    cout << top << '\n';
                    visited[top] = true;

                    for (auto &conn : adj[top])
                    {
                        if (visited[conn] == false)
                        {
                            currentStack.push(conn);
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
    newGraph.addEdge(0, 3, false);

    newGraph.printGraph();

    newGraph.DFSRecursive();

    newGraph.DFSIterative();

    return 0;
}