```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *A)
{

    if (A == NULL || A->next == NULL)
    {
        return A;
    }

    ListNode *slow = A;
    ListNode *fast = A;

    while (fast != NULL && slow != NULL)
    {

        slow = slow->next;

        if (fast->next == NULL)
        {
            return NULL;
        }
        else
        {
            fast = fast->next->next;
        }

        if (slow == fast)
        {
            break;
        }
    }

    if (slow == NULL || fast == NULL)
    {
        return NULL;
    }

    ListNode *curr = A;

    while (curr != slow)
    {
        slow = slow->next;
        curr = curr->next;
    }

    return curr;
}
```