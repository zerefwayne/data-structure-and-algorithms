#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, int> indexOf;
        vector<vector<string>> res;
        int counter = 0;

        for (auto &str : strs)
        {

            string new_str{str.begin(), str.end()};

            sort(new_str.begin(), new_str.end());

            if (indexOf.find(new_str) == indexOf.end())
            {
                indexOf[new_str] = counter++;
                vector<string> new_entry{str};
                res.emplace_back(new_entry);
            }
            else
            {
                res[indexOf[new_str]].emplace_back(str);
            }
        }

        return res;
    }
};