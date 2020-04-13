```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::deleteDuplicates(ListNode *A)
{

    ListNode *head = new ListNode(-1);
    head->next = A;

    ListNode *i = A;
    ListNode *j = NULL;
    ListNode *prev = head;

    int val;

    while (i != NULL)
    {

        val = i->val;
        j = i->next;

        while (j != NULL)
        {

            if (j->val == val)
            {
                j = j->next;
            }
            else
            {
                break;
            }
        }

        if (j == i->next)
        {
            prev = i;
        }
        else
        {
            prev->next = j;
        }

        i = j;
    }

    return head->next;
}
```