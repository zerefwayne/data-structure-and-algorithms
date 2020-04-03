#include <bits/stdc++.h>

using namespace std;

/*
    Design a stack which supports the following operations.

    Implement the CustomStack class:

    CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
    void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
    int pop() Pops and returns the top of stack or -1 if the stack is empty.
    void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.
*/

class CustomStack
{

public:
    stack<int> customStack;
    int maxSize;
    int size;

    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
        this->size = 0;
    }

    void push(int x)
    {
        if (this->size == this->maxSize)
        {
            return;
        }
        else
        {
            this->size++;
            this->customStack.push(x);
        }
    }

    int pop()
    {

        if (this->size == 0)
        {
            return -1;
        }

        int top = this->customStack.top();
        this->customStack.pop();
        this->size--;

        return top;
    }

    void increment(int k, int val)
    {

        stack<int> reverseStack;
        int count = this->size;

        while (!this->customStack.empty())
        {
            if (count <= k)
            {
                reverseStack.push(val + this->customStack.top());
            }
            else
            {
                reverseStack.push(this->customStack.top());
            }
            count--;
            this->customStack.pop();
        }

        while (!reverseStack.empty())
        {
            this->customStack.push(reverseStack.top());
            reverseStack.pop();
        }
    }
};
