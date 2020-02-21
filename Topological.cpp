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

    void topologicalSortUtil(int node, vector<bool> &visited, stack<int> &result)
    {

        visited[node] = true;

        for (auto &conn : adj[node])
        {

            if (visited[conn] = false)
            {

                topologicalSortUtil(conn, visited, result);
            }
        }

        result.push(node);
    }

    void topologicalSort(int startNode)
    {

        vector<bool> visited(V, false);
        stack<int> result;

        if (startNode < 0 || startNode >= V)
            return;

        topologicalSortUtil(startNode, visited, result);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == false)
            {
                topologicalSortUtil(i, visited, result);
            }
        }

        cout << "Topological Sort:\n\n";

        vector<int> result_array;

        while (!result.empty())
        {
            result_array.emplace_back(result.top());
            result.pop();
        }

        reverse(result_array.begin(), result_array.end());

        for (auto &node : result_array)
        {
            cout << node << '\n';
        }

        cout << '\n';
    }
};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 2, true);
    newGraph.addEdge(1, 2, true);
    newGraph.addEdge(1, 3, true);
    newGraph.addEdge(2, 4, true);

    newGraph.printGraph();

    newGraph.topologicalSort(0);

    return 0;
}