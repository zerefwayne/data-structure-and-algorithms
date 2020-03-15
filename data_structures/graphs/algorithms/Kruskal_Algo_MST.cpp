#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;

    Edge(int x, int y, int z)
    {
        src = x;
        dest = y;
        weight = z;
    }

    bool operator<(Edge b) const
    {
        return weight < b.weight;
    }
};

class DisjointSet
{

    unordered_map<int, int> mappings;
    unordered_map<int, int> rank;

public:
    void makeSet(int data)
    {

        if (mappings.find(data) == mappings.end())
        {
            mappings[data] = data;
            rank[data] = 0;
        }
    }

    int findSet(int data)
    {

        int parent = mappings[data];

        if (parent == data)
        {
            return parent;
        }

        mappings[data] = findSet(parent);

        return mappings[data];
    }

    void unionSets(int data1, int data2)
    {

        int parent1 = findSet(data1);
        int parent2 = findSet(data2);

        if (parent1 == parent2)
        {
            return;
        }

        int rank1 = rank[parent1];
        int rank2 = rank[parent2];

        if (rank1 > rank2)
        {
            mappings[parent2] = parent1;
        }
        else if (rank1 == rank2)
        {
            mappings[parent2] = parent1;
            rank[parent1] += 1;
        }
        else
        {
            mappings[parent1] = parent2;
        }
    }

    void printSet()
    {

        unordered_map<int, int>::iterator map_iter;

        cout << "Printing disjoint sets:\n\n";

        for (map_iter = mappings.begin(); map_iter != mappings.end(); map_iter++)
        {

            cout << (*map_iter).first << "->" << (*map_iter).second << '\n';
        }

        cout << '\n';
    }
};

void calculateKruskalMST(DisjointSet &disjointSet, vector<Edge> &edges)
{

    sort(edges.begin(), edges.end());

    int cost = 0;

    vector<Edge> result;

    for (const auto &edge : edges)
    {

        if (edge.src == edge.dest)
            continue;

        int end1 = disjointSet.findSet(edge.src);
        int end2 = disjointSet.findSet(edge.dest);

        if (end1 != end2)
        {

            cost += edge.weight;
            disjointSet.unionSets(end1, end2);
            result.emplace_back(edge);
        }
    }

    cout << "Kruskal MST Final Weight: " << cost << endl
         << endl;

    for (const auto &edge : result)
    {
        cout << edge.src << ' ' << edge.dest << ' ' << edge.weight << '\n';
    }

    cout << '\n';
}

int main()
{

    vector<Edge> edges;
    int V = 6;

    DisjointSet disjointSet = DisjointSet();

    for (int i = 0; i < V; i++)
    {
        disjointSet.makeSet(i);
    }

    edges.emplace_back(Edge(0, 1, 6));
    edges.emplace_back(Edge(0, 4, 5));
    edges.emplace_back(Edge(4, 1, 2));
    edges.emplace_back(Edge(1, 3, 3));
    edges.emplace_back(Edge(3, 2, 7));
    edges.emplace_back(Edge(2, 5, 4));
    edges.emplace_back(Edge(0, 5, 1));
    edges.emplace_back(Edge(5, 1, 1));

    disjointSet.printSet();

    calculateKruskalMST(disjointSet, edges);

    return 0;
}