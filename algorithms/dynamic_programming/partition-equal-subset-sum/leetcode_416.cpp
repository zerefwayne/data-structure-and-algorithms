#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartitionRecursive(vector<int> &nums, int index, vector<bool> &isFirstSetMember)
    {

        if (index == nums.size())
        {

            int sum1 = 0;
            int sum2 = 0;

            for (int i = 0; i < nums.size(); i++)
            {

                if (isFirstSetMember[i])
                {
                    sum1 += nums[i];
                }
                else
                {
                    sum2 += nums[i];
                }
            }

            return sum1 == sum2;
        }
        else
        {

            for (int i = index; i < nums.size(); i++)
            {

                isFirstSetMember[i] = true;

                if (canPartitionRecursive(nums, i + 1, isFirstSetMember))
                {
                    return true;
                }

                isFirstSetMember[i] = false;
            }

            return false;
        }
    }

    bool canPartition(vector<int> &nums)
    {

        if (nums.size() < 2)
        {
            return false;
        }

        vector<bool> isFirstSetMember(nums.size(), false);

        return canPartitionRecursive(nums, 0, isFirstSetMember);
    }
};

/*
    Bit Masking

    class Solution {
        public:
            bool canPartition(vector<int>& nums) {
                bitset<10001> bits(1);
                int sum = accumulate(nums.begin(), nums.end(), 0);
                for (auto n : nums) bits |= bits << n;
                return !(sum & 1) && bits[sum >> 1];
            }
    };
*/

/*
    Smart Technique

    class Solution {
        public:
            bool canPartition(vector<int>& nums) {
                int sum = 0;
                for(int i =0;i<nums.size();i++){
                    sum+= nums[i];
                }
                if(sum%2) return false;
                sum /= 2;
                sort(nums.rbegin(),nums.rend());
                return helper(nums, sum, 0);
            }
            bool helper(vector<int>& nums, int sum, int index){
                if(sum == nums[index]) return true;
                if(sum < nums[index]) return false;
                return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
            }
    };
*/