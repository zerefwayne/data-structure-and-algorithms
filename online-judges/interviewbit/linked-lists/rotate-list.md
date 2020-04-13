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

    int length = 0;
    ListNode *temp = A;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

ListNode *Solution::rotateRight(ListNode *A, int B)
{

    ListNode *popa = new ListNode(-1);

    popa->next = A;

    int len = length(A);

    if ((B % len) == 0)
    {
        return A;
    }

    B = B % len;

    int splitDistance = len - B;

    int counter = 0;

    ListNode *split = popa;
    ListNode *end = popa;

    while (end->next != NULL)
    {

        if (counter < splitDistance)
        {
            split = split->next;
            counter++;
        }

        end = end->next;
    }

    popa->next = split->next;
    split->next = NULL;
    end->next = A;

    return popa->next;
}
```