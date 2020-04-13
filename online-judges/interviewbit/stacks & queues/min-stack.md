```cpp
stack<pair<int, int>> minStack;
int stackSize = 0;

MinStack::MinStack()
{
    stackSize = 0;
    while (!minStack.empty())
    {
        minStack.pop();
    }
}

void MinStack::push(int x)
{
    if (stackSize == 0)
    {
        minStack.push(make_pair(x, x));
        stackSize++;
    }
    else
    {
        int min_top = minStack.top().second;
        minStack.push(make_pair(x, min(min_top, x)));
        stackSize++;
    }
}

void MinStack::pop()
{
    if (stackSize > 0)
    {
        minStack.pop();
        stackSize--;
    }
}

int MinStack::top()
{
    if (stackSize > 0)
    {
        return minStack.top().first;
    }
    else
    {
        return -1;
    }
}

int MinStack::getMin()
{
    if (stackSize > 0)
    {
        return minStack.top().second;
    }
    else
    {
        return -1;
    }
}
```