/*
    https://www.hackerrank.com/challenges/torque-and-development/problem

    The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest programmer of HackerLand, the ruler wants your help to repair the roads and build some new libraries efficiently.

    HackerLand has  cities numbered from  to . The cities are connected by  bidirectional roads. A citizen has access to a library if:

    Their city contains a library.
    They can travel by road from their city to a city containing a library.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class DisjointSet
{

    int n;
    vector<int> parents;
    vector<int> ranks;
    int c_lib;
    int c_road;

public:
    DisjointSet(int n, int c_lib, int c_road)
    {
        this->n = n;
        this->c_lib = c_lib;
        this->c_road = c_road;

        //Creating a disjoint set
        for (int i = 0; i < this->n; i++)
        {
            this->parents.emplace_back(i);
            this->ranks.emplace_back(0);
        }
    }

    int minimumCostToRebuild()
    {

        unordered_map<int, int> components;

        int cost = 0;

        for (int i = 0; i < this->n; i++)
        {
            components[this->parents[i]]++;
        }

        for (auto it = components.begin(); it != components.end(); it++)
        {
            int cities = it->second;

            cost += min(this->c_lib * cities, this->c_lib + this->c_road * (cities - 1));
        }

        return cost;
    }

    void unionSets(int a, int b)
    {

        int parent_a = this->findSet(a);
        int parent_b = this->findSet(b);

        if (this->ranks[parent_a] > this->ranks[parent_b])
        {
            this->ranks[parent_a] += 1;
            this->parents[b] = parent_a;
        }
        else if (this->ranks[parent_b] > this->ranks[parent_a])
        {
            this->ranks[parent_b] += 1;
            this->parents[a] = parent_b;
        }
        else
        {
            this->parents[b] = parent_a;
        }
    }

    int findSet(int n)
    {
        if (this->parents[n] == n)
        {
            return n;
        }
        else
        {
            this->parents[n] = this->findSet(this->parents[n]);
            return this->parents[n];
        }
    }
};

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{

    DisjointSet ds(n, c_lib, c_road);

    for (auto &road : cities)
    {

        int src = road[0] - 1;
        int dest = road[1] - 1;

        ds.unionSets(src, dest);
    }

    return ds.minimumCostToRebuild();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++)
        {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++)
            {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}