```cpp

int binaryToGray(int num)
{
    return num ^ (num >> 1);
}

vector<int> Solution::grayCode(int A)
{
    vector<int> res;
    for (auto i = 0; i < pow(2, A); ++i)
        res.emplace_back(binaryToGray(i));
    return res;
}

```