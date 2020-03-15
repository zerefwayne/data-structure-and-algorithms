#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int dest;
    int weight;

    Node(int _dest, int _weight)
    {
        this->dest = _dest;
        this->weight = _weight;
    }

    bool operator==(const Node &b) const
    {
        return this->dest == b.dest;
    }

    bool operator<(const Node &b) const
    {
        return this->weight < b.weight;
    }

    bool operator>(const Node &b) const
    {
        return this->weight > b.weight;
    }
};

class Graph
{

public:
    vector<vector<Node>> adj;
    int V;

    Graph(int V)
    {
        this->V = V;
        this->adj.resize(this->V);
    }

    void addEdge(int src, int dest, int weight, bool isUnidirectional)
    {

        if (src >= 0 && src < V && dest >= 0 && dest < V && dest != src)
        {

            if (find(adj[src].begin(), adj[src].end(), Node(dest, -1)) == adj[src].end())
            {
                adj[src].emplace_back(Node(dest, weight));
            }

            if (isUnidirectional == false)
            {

                if (find(adj[dest].begin(), adj[dest].end(), Node(src, -1)) == adj[dest].end())
                {
                    adj[dest].emplace_back(Node(src, weight));
                }
            }
        }
    }

    void printGraph()
    {

        cout<<"Printing the graph:\n\n";

        for (int i = 0; i < V; i++)
        {

            cout << i << "->";

            for (auto &vertex : adj[i])
            {

                cout << vertex.dest << "(" << vertex.weight << ")"
                     << "->";
            }

            cout << '\n';
        }

        cout << '\n';
    }

};

int main()
{

    Graph newGraph = Graph(5);

    newGraph.addEdge(0, 4, 9, false);
    newGraph.addEdge(4, 1, 2, false);
    newGraph.addEdge(1, 2, 5, false);
    newGraph.addEdge(2, 0, 6, false);
    newGraph.addEdge(0, 3, 2, false);
    newGraph.addEdge(3, 1, 3, false);

    newGraph.printGraph();

    return 0;
}