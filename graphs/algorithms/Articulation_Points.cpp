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

    void articulationPointsUtil(int root, int node, int &time, vector<int> &parents, unordered_set<int> &visited, vector<int> &visitedTimes, vector<int> &lowTimes, list<int> &artPoints)
    {

        visitedTimes[node] = time;
        lowTimes[node] = time;
        visited.insert(node);
        bool isArticulationPoint = false;

        time += 1;

        int childCount = 0;

        for (auto &child : this->adj[node])
        {

            if (child == parents[node])
                continue;

            if (visited.find(child) == visited.end())
            {
                parents[child] = node;
                childCount++;
                articulationPointsUtil(root, child, time, parents, visited, visitedTimes, lowTimes, artPoints);

                if (visitedTimes[node] <= lowTimes[child])
                {
                    isArticulationPoint = true;
                }
                else
                {

                    lowTimes[node] = min(lowTimes[child], lowTimes[node]);
                }
            }
            else
            {

                lowTimes[node] = min(lowTimes[child], lowTimes[node]);
            }
        }

        if (node == root)
        {
            if (childCount >= 2)
            {
                artPoints.emplace_back(node);
            }
        }
        else
        {
            if (isArticulationPoint)
            {
                artPoints.emplace_back(node);
            }
        }
    }

    void articulationPoints()
    {

        int root = 0;

        vector<int> visitedTimes(this->V, -1);
        vector<int> lowTimes(this->V, -1);
        vector<int> parents(this->V, -1);
        int time = 0;
        unordered_set<int> visited;
        list<int> artPoints;

        parents[0] = -1;
        articulationPointsUtil(root, root, time, parents, visited, visitedTimes, lowTimes, artPoints);

        cout << "Articulation Points: ";

        for (auto &point : artPoints)
        {
            cout << point << ' ';
        }

        cout << "\n\n";
    }
};

int main()
{

    Graph newGraph = Graph(8);

    newGraph.addEdge(0, 1, false);
    newGraph.addEdge(1, 2, false);
    newGraph.addEdge(2, 3, false);
    newGraph.addEdge(3, 1, false);
    newGraph.addEdge(0, 4, false);
    newGraph.addEdge(4, 5, false);
    newGraph.addEdge(5, 7, false);
    newGraph.addEdge(5, 6, false);
    newGraph.addEdge(6, 4, false);

    newGraph.printGraph();

    newGraph.articulationPoints();

    return 0;
}