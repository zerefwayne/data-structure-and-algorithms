#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2) {
            return false;
        }
        
        unordered_set<int> visited;
        
        for(int i = 0; i < nums.size(); i++) {
            if(visited.find(nums[i]) != visited.end()){
                return true;
            }
            visited.insert(nums[i]);
        }
        
        return false;
        
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int> {nums.begin(), nums.end()}.size() < nums.size();        
    }
};