```cpp
ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B)
{

    ListNode *popa = new ListNode(-1);

    ListNode *a = A;
    ListNode *b = B;
    ListNode *prev = popa;

    while (a != NULL && b != NULL)
    {

        if (a->val <= b->val)
        {

            prev->next = a;
            a = a->next;
            prev = prev->next;
        }
        else
        {

            prev->next = b;
            b = b->next;
            prev = prev->next;
        }
    }

    while (a != NULL)
    {

        prev->next = a;
        a = a->next;
        prev = prev->next;
    }

    while (b != NULL)
    {

        prev->next = b;
        b = b->next;
        prev = prev->next;
    }

    return popa->next;
}
```