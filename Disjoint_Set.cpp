#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{

    unordered_map<int, int> mapping;
    unordered_map<int, int> rank;

public:
    void makeSet(int data)
    {
        if (mapping.find(data) == mapping.end())
        {
            mapping[data] = data;
            rank[data] = 0;
        }
    }

    int findSet(int data)
    {
        int parent = mapping[data];
        if (parent == data)
            return parent;
        mapping[data] = findSet(parent);
        return mapping[data];
    }

    void unionSets(int data1, int data2)
    {

        int parent1 = findSet(data1);
        int parent2 = findSet(data2);

        if (parent1 == parent2)
        {
            return;
        }

        if (rank[parent1] >= rank[parent2])
        {

            rank[parent1] = (rank[parent1] == rank[parent2]) ? rank[parent1] + 1 : rank[parent1];
            mapping[parent2] = parent1;
        }
        else
        {
            mapping[parent1] = parent2;
        }
    }

    void printSet()
    {

        unordered_map<int, int>::iterator map_iter;

        cout << "Printing disjoint sets:\n\n";

        for (map_iter = mapping.begin(); map_iter != mapping.end(); map_iter++)
        {

            cout << (*map_iter).first << "->" << (*map_iter).second << '\n';
        }

        cout << '\n';
    }
};

int main()
{

    DisjointSet dis_set = DisjointSet();

    for (int i = 0; i < 7; i++)
    {
        dis_set.makeSet(i + 1);
    }

    dis_set.printSet();

    dis_set.unionSets(1, 2);
    dis_set.unionSets(3, 4);

    dis_set.unionSets(5, 6);
    dis_set.unionSets(6, 7);

    dis_set.unionSets(4, 6);

    dis_set.unionSets(6, 7);

    dis_set.printSet();

    return 0;
}