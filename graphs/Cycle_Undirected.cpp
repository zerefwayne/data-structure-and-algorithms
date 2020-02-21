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

    bool cycleDFSUtil(int node, vector<bool> &visited, int parent)
    {

        visited[node] = true;

        for (auto &child : adj[node])
        {

            if (!visited[child])
            {
                if (cycleDFSUtil(child, visited, node))
                {
                    return true;
                }
            }
            else if (child != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool detectCycleUndirectedGraphDFS()
    {

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {

            if (visited[i] == false)
            {

                if (cycleDFSUtil(i, visited, -1))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 1, false);
    newGraph.addEdge(1, 2, false);
    newGraph.addEdge(2, 0, false);

    newGraph.printGraph();

    cout << "Is graph cyclic: " << newGraph.detectCycleUndirectedGraphDFS() << endl;

    return 0;
}