```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode *A)
{

    ListNode *temp = A;

    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{

    if (A == NULL)
    {
        return NULL;
    }

    int len = length(A);

    if (B > len)
    {
        return A->next;
    }

    ListNode *popa = new ListNode(-1);
    popa->next = A;

    int count = 0;

    ListNode *temp = popa;
    ListNode *prev = popa;

    while (count < len - B + 1)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;

    return popa->next;
}
```