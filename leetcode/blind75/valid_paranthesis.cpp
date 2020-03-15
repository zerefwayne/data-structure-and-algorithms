#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bracketToCode(char b)
    {

        switch (b)
        {
        case '(':
            return 0;
            break;
        case ')':
            return 1;
            break;
        case '[':
            return 2;
            break;
        case ']':
            return 3;
            break;
        case '{':
            return 4;
            break;
        case '}':
            return 5;
            break;
        }

        return 0;
    }

    bool isValid(string s)
    {

        stack<int> paranStack;

        for (int i = 0; i < s.length(); i++)
        {

            int x = this->bracketToCode(s[i]);

            if (x % 2 == 0)
            {

                paranStack.push(x);
            }
            else
            {

                if (paranStack.empty() == true)
                {
                    return false;
                }

                int top = paranStack.top();

                if (top == x - 1)
                {
                    paranStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return paranStack.empty();
    }
};