```cpp
struct CompareNodes
{
    bool operator()(ListNode *const &n1, ListNode *const &n2)
    {
        return n1->val > n2->val;
    }
};

ListNode *Solution::mergeKLists(vector<ListNode *> &A)
{

    ListNode *popa = new ListNode(-1);

    ListNode *curr = popa;

    priority_queue<ListNode *, vector<ListNode *>, CompareNodes> queue;

    for (const auto &node : A)
    {
        queue.push(node);
    }

    while (!queue.empty())
    {

        ListNode *top = queue.top();
        queue.pop();
        curr->next = top;
        curr = curr->next;

        if (curr->next != NULL)
        {
            queue.push(curr->next);
        }
    }

    return popa->next;
}
```