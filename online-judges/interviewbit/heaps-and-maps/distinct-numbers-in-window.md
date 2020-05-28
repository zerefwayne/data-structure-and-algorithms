```cpp
vector<int> Solution::dNums(vector<int> &A, int B)
{

    unordered_map<int, int> nums;
    vector<int> ans;

    int N = A.size();

    if (B > N)
    {
        return ans;
    }

    for (int i = 0; i < N; i++)
    {

        nums[A[i]]++;

        if (i < B)
        {
            if (i == B - 1)
            {
                ans.emplace_back(nums.size());
            }
            continue;
        }

        int rem = A[i - B];

        nums[rem]--;

        if (nums[rem] == 0)
        {
            nums.erase(rem);
        }

        ans.emplace_back(nums.size());
    }

    return ans;
}
```