```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverseList(ListNode *A)
{

    ListNode *prev = NULL;
    ListNode *temp = A;
    ListNode *next = NULL;

    while (temp != NULL)
    {

        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

int lengthList(ListNode *A)
{

    ListNode *temp = A;

    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

int Solution::lPalin(ListNode *A)
{

    ListNode *head = new ListNode(-1);
    head->next = A;

    int length = lengthList(head->next);

    if (length < 2)
    {
        return 1;
    }

    bool isOdd = length % 2 == 1;

    ListNode *prev = NULL;
    ListNode *slow = head->next;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *split = NULL;

    if (isOdd)
    {
        split = slow->next;
    }
    else
    {
        split = slow;
    }

    prev->next = NULL;

    split = reverseList(split);

    ListNode *a = head->next;
    ListNode *b = split;

    while (a != NULL && b != NULL)
    {

        if (a->val != b->val)
        {
            return 0;
        }

        a = a->next;
        b = b->next;
    }

    return 1;
}
```