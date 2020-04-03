```cpp
string loc(string a, string b)
{

    string res;

    if (a < b)
    {
        res = a + "," + b;
    }
    else
    {
        res = b + "," + a;
    }

    return res;
}

class UndergroundSystem
{

    unordered_map<int, pair<string, int>> current;
    unordered_map<string, pair<int, int>> archive;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {

        current[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {

        pair<string, int> journey = make_pair(current[id].first, current[id].second);
        current.erase(id);

        int duration = t - journey.second;
        string key = loc(journey.first, stationName);

        // cout<<"Checkout at: "<<key<<'\n';

        if (archive.find(key) == archive.end())
        {
            archive[key] = make_pair(1, duration);
        }
        else
        {
            archive[key].first++;
            archive[key].second += duration;
        }
    }

    double getAverageTime(string startStation, string endStation)
    {

        string key = loc(startStation, endStation);

        // cout<<"Average time at: "<<key<<' '<<archive[key].second<<' '<<archive[key].first<<'\n';

        double res = (double)archive[key].second / (double)archive[key].first;
        return res;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```