## Approach 1: Compressing array to counter array of sqrt(n) size

```cpp
int Solution::repeatedNumber(const vector<int> &A)
{

    int n = A.size();
    int _max = *max_element(A.begin(), A.end());

    int size = ceil(sqrt(_max));

    vector<int> counter(size, 0);
    int target = -1;

    for (auto &num : A)
    {
        int bucket = floor(num / size);

        counter[bucket]++;

        if (counter[bucket] > size)
        {
            target = bucket;
            break;
        }
    }

    if (target == -1)
    {
        return -1;
    }

    unordered_set<int> count;

    for (auto &num : A)
    {
        int bucket = floor(sqrt(num));
        if (bucket == target)
        {
            if (count.find(num) != count.end())
            {
                return num;
            }
            else
            {
                count.insert(num);
            }
        }
    }

    return -1;
}
```
