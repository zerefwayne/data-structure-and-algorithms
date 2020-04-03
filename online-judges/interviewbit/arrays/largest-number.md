## Approach 1 O(nlogn) Smart Observation

```cpp
bool checkLarger(int a, int b)
{
    string aa = to_string(a);
    string bb = to_string(b);
    string ab = aa + bb;
    string ba = bb + aa;
    if (ab > ba)
    {
        return true;
    }
    return false;
}

string Solution::largestNumber(const vector<int> &A)
{
    vector<int> nums = A;
    sort(nums.begin(), nums.end(), checkLarger);
    string res = "";
    for (auto num : nums)
    {
        res += to_string(num);
    }
    if (A[0] == 0)
    {
        return "0";
    }
    return res;
}
```