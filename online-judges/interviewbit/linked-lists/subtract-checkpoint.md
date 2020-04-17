```cpp
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

ListNode *Solution::subtract(ListNode *A)
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

    ListNode *prev_a = A;
    ListNode *curr_a = A;
    ListNode *curr_b = B;

    while (curr_a != NULL)
    {
        prev_a = curr_a;
        curr_a->val = curr_b->val - curr_a->val;
        curr_a = curr_a->next;
        curr_b = curr_b->next;
    }

    B = reverse(B);

    prev_a->next = B;

    return A;
}
```