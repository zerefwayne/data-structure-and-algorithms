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
            cout << it->first << ' ' << it->second << '\n';
            int cities = it->second;

            cost += min(this->c_lib * cities, this->c_lib + this->c_road * (cities - 1));
        }

        cout << '\n';

        return cost;
    }

    void unionSets(int a, int b)
    {

        int parent_a = this->findSet(a);
        int parent_b = this->findSet(b);

        if (this->ranks[parent_a] > this->ranks[parent_b])
        {
            this->parents[b] = parent_a;
        }
        else if (this->ranks[parent_b] > this->ranks[parent_a])
        {
            this->parents[a] = parent_b;
        }
        else
        {
            this->ranks[parent_a] += 1;
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

    if (c_lib < c_road) {
        return n*c_lib;
    }

    for (auto &road : cities)
    {

        int src = road[0] - 1;
        int dest = road[1] - 1;

        ds.unionSets(src, dest);
        ds.unionSets(dest, src);
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

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
