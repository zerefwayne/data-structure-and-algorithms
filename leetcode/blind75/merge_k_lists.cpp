#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, ListNode **>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        ListNode *dummy = new ListNode(0);

        priority_queue<pii, vector<pii>, greater<pii>> headHeap;

        for (auto &list : lists)
        {
            if (list != NULL)
            {
                headHeap.push(make_pair(list->val, &list));
            }
        }

        while (!headHeap.empty())
        {

            pii top = headHeap.top();

            ListNode *node = *top.second;

            headHeap.pop();

            dummy->next = node;
            node = node->next;
            dummy = dummy->next;

            if (node != NULL)
            {
                headHeap.push(make_pair(node->val, &node));
            }
        }

        return dummy->next;
    }
};