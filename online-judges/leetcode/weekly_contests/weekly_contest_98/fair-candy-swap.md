[Leetcode Weekly Contest 98 - Fair Candy Swap](https://leetcode.com/contest/weekly-contest-98/problems/fair-candy-swap/)

## Approach 1: Sorting and then Two Pointer O(nlogn)

```cpp
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {

        int sumOfA = accumulate(A.begin(), A.end(), 0);
        int sumOfB = accumulate(B.begin(), B.end(), 0);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<int> first;
        vector<int> second;

        bool switched = false;

        if (sumOfA > sumOfB)
        {
            first = A;
            second = B;
        }
        else
        {
            switched = true;
            first = B;
            second = A;
        }

        reverse(first.begin(), first.end());

        int i = 0;
        int j = 0;
        int diff;

        int req_diff = abs(sumOfA - sumOfB) / 2;

        while (i < first.size() && j < second.size())
        {

            diff = first[i] - second[j];

            if (diff == req_diff)
            {
                if (!switched)
                {
                    return vector<int>{first[i], second[j]};
                }
                else
                {
                    return vector<int>{second[j], first[i]};
                }
            }
            else if (diff < req_diff)
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return vector<int>{};
    }
};
```

## Approach 2: HashSet O(n)

Theory: x is removed, y is added sumA and x added y removed sum B, equate the equations, then use HashSet

```cpp
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {

        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> set_a{A.begin(), A.end()};
        for (auto &b : B)
        {
            if (set_a.count(b + diff) > 0)
            {
                return vector<int>{b + diff, b};
            }
        }

        return vector<int>();
    }
};
```

## Approach 3: BitSet time O(n) much faster than HashSet (FASTEST)

```cpp
Solution()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
{
    int Asum = 0;
    int Bsum = 0;
    bitset<100001> Aset;
    for (int num : A)
    {
        Asum += num;
        Aset.set(num);
    }
    for (int num : B)
    {
        Bsum += num;
    }
    int diff = (Asum - Bsum) / 2;

    for (int y : B)
    {
        int x = y + diff;
        if (x > 0 && x < 100001 && Aset.test(x))
        {
            return {x, y};
        }
    }
    return {-1, -1};
}
```