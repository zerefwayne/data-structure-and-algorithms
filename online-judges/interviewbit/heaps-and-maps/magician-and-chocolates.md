```cpp
int mod = 1000000007;

int Solution::nchoc(int A, vector<int> &B)
{

    int c = 0;

    priority_queue<int> queue;

    for (const auto &bag : B)
    {
        queue.push(bag);
    }

    for (int i = 0; i < A; i++)
    {

        int top = queue.top();
        queue.pop();

        c = (c % mod + top % mod) % mod;

        queue.push(top / 2);
    }

    return c % mod;
}
```