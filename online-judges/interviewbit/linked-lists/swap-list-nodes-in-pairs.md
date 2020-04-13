```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs(ListNode *A)
{

    ListNode *popa = new ListNode(-1);
    popa->next = A;

    ListNode *prev;
    ListNode *i;
    ListNode *j;

    prev = popa;

    while (prev->next != NULL && prev->next->next != NULL)
    {

        i = prev->next;
        j = prev->next->next;

        prev->next = j;
        i->next = j->next;
        j->next = i;
        prev = i;
    }

    return popa->next;
}
```