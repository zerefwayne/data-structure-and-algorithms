```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{

    int carry = 0;

    ListNode *a = A;
    ListNode *b = B;
    ListNode *popa = new ListNode(-1);
    ListNode *temp = popa;

    while (a != NULL && b != NULL)
    {

        int val = a->val + b->val + carry;
        int digit;

        if (val > 9)
        {
            digit = val - 9;
            carry = 1;
        }
        else
        {
            digit = val;
            carry = 0;
        }

        temp->next = new ListNode(digit);
        temp = temp->next;

        a = a->next;
        b = b->next;
    }

    while (a != NULL)
    {

        int val = a->val + carry;
        int digit;

        if (val > 9)
        {
            digit = val - 9;
            carry = 1;
        }
        else
        {
            digit = val;
            carry = 0;
        }

        temp->next = new ListNode(digit);
        temp = temp->next;

        a = a->next;
    }

    while (b != NULL)
    {

        int val = b->val + carry;
        int digit;

        if (val > 9)
        {
            digit = val - 9;
            carry = 1;
        }
        else
        {
            digit = val;
            carry = 0;
        }

        temp->next = new ListNode(digit);
        temp = temp->next;

        b = b->next;
    }

    if (carry == 1) {
        temp -> next = new ListNode(1);
    }

    return popa->next;
}
```
