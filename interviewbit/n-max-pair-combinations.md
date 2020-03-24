## Approach 1: MaxHeap using sum, i, j as nodes

```cpp
struct HeapNode
{
    int sum;
    int i;
    int j;

    HeapNode(int sum, int i, int j) : sum(sum), i(i), j(j) {}
};

struct CompareNode
{
    bool operator()(HeapNode const &a, HeapNode const &b)
    {
        return a.sum < b.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{

    vector<int> res;

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int ni = 0;
    int nj = 0;
    pair<int, int> loc;

    set<pair<int, int>> isPresent;

    priority_queue<HeapNode, vector<HeapNode>, CompareNode> pq;

    pq.push(HeapNode(A[0] + B[0], 0, 0));
    isPresent.insert(make_pair(0, 0));

    for (int n = 0; n < A.size(); n++)
    {

        HeapNode top = pq.top();
        pq.pop();

        res.emplace_back(top.sum);

        ni = top.i + 1;
        nj = top.j;
        loc = make_pair(ni, nj);

        if (isPresent.find(loc) == isPresent.end())
        {
            pq.push(HeapNode(A[ni] + B[nj], ni, nj));
            isPresent.insert(loc);
        }

        ni = top.i;
        nj = top.j + 1;
        loc = make_pair(ni, nj);

        if (isPresent.find(loc) == isPresent.end())
        {
            pq.push(HeapNode(A[ni] + B[nj], ni, nj));
            isPresent.insert(loc);
        }
    }

    return res;
}
```