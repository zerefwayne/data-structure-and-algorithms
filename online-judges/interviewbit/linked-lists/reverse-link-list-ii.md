```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverseCount(ListNode *A, int num)
{

    int count = 0;

    ListNode *curr = A;
    ListNode *prev = NULL;
    ListNode *next;

    while (count < num)
    {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        count++;
    }

    A->next = curr;

    return prev;
}

ListNode *Solution::reverseBetween(ListNode *A, int B, int C)
{

    ListNode *popa = new ListNode(-1);

    popa->next = A;

    ListNode *temp = popa;
    ListNode *prev = popa;

    int count = 0;

    while (count < B)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = reverseCount(prev->next, C - B + 1);

    return popa->next;
}
```