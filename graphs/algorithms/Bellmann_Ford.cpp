#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;

    Edge(int _src, int _dest, int _weight)
    {
        this->src = _src;
        this->dest = _dest;
        this->weight = _weight;
    }

    bool operator==(const Edge &b) const
    {
        return this->dest == b.dest && this->src == b.src;
    }

    bool operator<(const Edge &b) const
    {
        return this->weight < b.weight;
    }

    bool operator>(const Edge &b) const
    {
        return this->weight > b.weight;
    }
};

bool edgeComparator(const Edge &a, const Edge &b)
{

    return a.src < b.src;
}

class EdgeGraph
{

public:
    vector<Edge> adj;
    int V;

    EdgeGraph(int V)
    {
        this->V = V;
    }

    void addEdge(int src, int dest, int weight, bool isUnidirectional)
    {

        if (src >= 0 && src < V && dest >= 0 && dest < V && dest != src)
        {

            if (find(adj.begin(), adj.end(), Edge(src, dest, -1)) == adj.end())
            {
                adj.emplace_back(Edge(src, dest, weight));
            }

            if (find(adj.begin(), adj.end(), Edge(dest, src, -1)) == adj.end())
            {
                adj.emplace_back(Edge(dest, src, weight));
            }
        }
    }

    void printEdges()
    {

        cout << "Printing the Edges:\n\n";

        for (auto &vertex : this->adj)
        {
            cout << vertex.src << " " << vertex.dest << " " << vertex.weight << '\n';
        }

        cout << '\n';
    }

    void sortEdges()
    {
        sort(adj.begin(), adj.end(), edgeComparator);
    }

    void bellmann_ford(int source)
    {

        vector<int> distances(this->V, INT_MAX);

        distances[source] = 0;
        unordered_map<int, int> parents;
        parents[source] = -1;
        bool canBreak = false;

        for (int epoch = 0; epoch < this->V; epoch++)
        {

            canBreak = true;
            cout << "Epoch " << epoch + 1 << '\n'
                 << '\n';

            for (auto &edge : this->adj)
            {

                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;

                if (distances[u] != INT_MAX && distances[v] > distances[u] + w)
                {
                    canBreak = false;
                    cout << "Updating " << v << " " << distances[v] << " to " << distances[u] + w << '\n';
                    parents[v] = u;
                    distances[v] = distances[u] + w;
                }
            }

            if (canBreak)
            {
                cout << "Stable state achieved.\n\n";
                break;
            }
            else
            {
                cout << '\n';
            }
        }

        cout << "Source: " << source << '\n'
             << '\n';

        for (int i = 0; i < this->V; i++)
        {

            if (i == source)
                continue;

            cout << i << " " << distances[i] << " " << parents[i] << '\n';
        }

        cout << '\n';
    }
};

int main()
{

    EdgeGraph newGraph = EdgeGraph(5);

    newGraph.addEdge(0, 4, 9, false);
    newGraph.addEdge(4, 1, 2, false);
    newGraph.addEdge(1, 2, 5, false);
    newGraph.addEdge(2, 0, 6, false);
    newGraph.addEdge(0, 3, 2, false);
    newGraph.addEdge(3, 1, 3, false);

    // newGraph.printEdges();

    // newGraph.sortEdges();

    newGraph.printEdges();

    newGraph.bellmann_ford(0);

    return 0;
}