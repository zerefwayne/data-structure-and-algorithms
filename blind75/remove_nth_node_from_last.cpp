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
    int calculateSize(ListNode *head)
    {

        int count = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int size = this->calculateSize(head);

        if (n == size)
        {
            return head->next;
        }

        ListNode *temp = head;
        int forwardSteps = size - n - 1;

        while (forwardSteps--)
        {
            temp = temp->next;
        }

        temp = temp->next;

        return head;
    }
};