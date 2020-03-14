#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }

        ListNode *temp = head;
        ListNode *fwd;
        ListNode *nxt;
        ListNode *tmp;

        while (temp->next != NULL && temp->next->next != NULL)
        {

            fwd = temp;

            while (fwd->next->next != NULL)
            {
                fwd = fwd->next;
            }

            tmp = fwd->next;
            fwd->next = NULL;
            nxt = temp->next;

            temp->next = tmp;
            temp = temp->next;
            fwd = nxt;
            temp->next = fwd;
            temp = temp->next;
        }
    }
};