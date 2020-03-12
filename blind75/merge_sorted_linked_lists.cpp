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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }

        int val1 = l1->val;
        int val2 = l2->val;

        ListNode *head = NULL;
        ListNode *temp = NULL;

        if (val1 <= val2)
        {
            head = l1;
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            temp = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL)
        {

            int val1 = l1->val;
            int val2 = l2->val;

            if (val1 <= val2)
            {

                if (temp->next == l1)
                {
                    temp = l1;
                    l1 = l1->next;
                }
                else
                {
                    temp->next = l1;
                    l1 = l1->next;
                    temp = temp->next;
                }
            }
            else
            {
                if (temp->next == l2)
                {

                    temp = l2;
                    l2 = l2->next;
                }
                else
                {

                    temp->next = l2;
                    l2 = l2->next;
                    temp = temp->next;
                }
            }
        }

        if (l1 == NULL)
        {
            temp->next = l2;
        }
        else
        {
            temp->next = l1;
        }

        return head;
    }
};