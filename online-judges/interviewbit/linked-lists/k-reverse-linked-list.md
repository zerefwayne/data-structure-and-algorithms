```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *A)
{

    ListNode *prev = NULL;
    ListNode *curr = A;
    ListNode *next = curr->next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *Solution::reverseList(ListNode *A, int B)
{

    ListNode *popa = new ListNode(-1);
    popa->next = A;

    ListNode *curr = popa;
    ListNode *i = NULL;
    ListNode *prev = NULL;
    ListNode *next_curr = NULL;

    int counter = 0;

    while (curr->next != NULL)
    {

        i = curr;
        next_curr = curr->next;
        counter = 0;

        while (counter <= B)
        {
            counter++;
            prev = i;
            i = i->next;
        }

        prev->next = NULL;
        curr->next = reverse(curr->next);
        curr = next_curr;
        curr->next = i;
    }

    return popa->next;
}
```