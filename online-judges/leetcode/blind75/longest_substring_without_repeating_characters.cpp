#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size() < 2) {
            return s.size();
        }

        unordered_map<char, int> lastIndexOf;

        lastIndexOf[s[0]] = 0;

        int longest_substr = 1;

        int l = 0;

        for(int r = 1; r < s.length(); r++) {

            if(lastIndexOf.find(s[r]) == lastIndexOf.end()) {
                lastIndexOf[s[r]] = r;
                longest_substr = max(longest_substr, r-l+1);
            } else {

                if(r == s.length() - 1) {
                    break;
                }

                int curr_index = lastIndexOf[s[r]];

                while(l <= curr_index) {
                    lastIndexOf.erase[s[l]];
                    l++;
                }

                lastIndexOf[s[r]] = r;

            }

        }

        return longest_substr;

    }
};