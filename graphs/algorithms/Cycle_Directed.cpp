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

    void detectDirectedCycleUtil(int node, int parent, vector<bool> &white, vector<bool> &gray, vector<bool> &black, unordered_map<int, int> &parents)
    {
        cout<<"Visiting node: "<<node<<'\n';
        // Remove node from white list
        white[node] = false;

        // Insert node into gray list
        gray[node] = true;

        // Assign the parent of the node who introduced it
        parents[node] = parent;

        for (auto &child : adj[node])
        {

            if (black[child] == true)
                continue;

            if (gray[child] == true)
            {
                cout << "Cycle detected at: " << node << "->" << child << " Parent: " << parents[child] << '\n';
            }

            if (white[child] == true)
            {
                detectDirectedCycleUtil(child, node, white, gray, black, parents);
            }
        }

        //Remove node from graySet
        gray[node] = false;

        //Insert node into blackSet
        black[node] = true;
    }

    void detectDirectedCycle()
    {

        vector<bool> white(V, true);
        vector<bool> gray(V, false);
        vector<bool> black(V, false);
        unordered_map<int, int> parents;

        // For considering all nodes in an unconnected graph

        for (int i = 0; i < V; i++)
        {
            if (white[i])
            {
                detectDirectedCycleUtil(i, -1, white, gray, black, parents);
            }
        }
    }
};

int main()
{

    Graph newGraph = Graph(6);

    newGraph.addEdge(0, 1, true);
    newGraph.addEdge(1, 2, true);
    newGraph.addEdge(2, 0, true);
    newGraph.addEdge(2, 3, true);
    newGraph.addEdge(3, 0, true);
    newGraph.addEdge(2, 4, true);
    newGraph.addEdge(4, 3, true);

    newGraph.printGraph();

    newGraph.detectDirectedCycle();

    return 0;
}