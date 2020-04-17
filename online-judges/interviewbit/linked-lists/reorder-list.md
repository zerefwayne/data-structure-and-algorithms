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
    ListNode *next = NULL;
    ListNode *curr = A;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *Solution::reorderList(ListNode *A)
{

    if (A == NULL || A->next == NULL)
    {
        return A;
    }

    //Finding the mid point

    ListNode *prev;
    ListNode *slow = A;
    ListNode *fast = A;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *B = slow;
    prev->next = NULL;

    B = reverse(B);

    ListNode *popa = new ListNode(-1);
    popa->next = A;
    ListNode *curr = A;

    while (curr != NULL)
    {

        A = A->next;
        curr->next = B;

        curr = curr->next;
        B = B->next;

        if (A != NULL)
        {
            curr->next = A;
        }

        curr = A;
    }

    return popa->next;
}
```