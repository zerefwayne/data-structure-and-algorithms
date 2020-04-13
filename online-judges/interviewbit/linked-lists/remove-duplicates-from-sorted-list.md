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

    ListNode *i = head->next;
    ListNode *j = NULL;
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

        i->next = j;
        i = i->next;
    }

    return head->next;
}
```