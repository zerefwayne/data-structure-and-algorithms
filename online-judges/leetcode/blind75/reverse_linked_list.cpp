#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Iteratively

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *temp = head;
        ListNode *next = temp;

        while (temp != NULL)
        {
            next = next->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
};