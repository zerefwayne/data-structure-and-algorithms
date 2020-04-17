```cpp
int Solution::braces(string A)
{

    stack<char> st;

    for (int i = 0; i < A.length(); i++)
    {

        if (A[i] == ')')
        {

            int count = 0;

            while (st.top() != '(')
            {
                count++;
                st.pop();
            }

            if (count == 1)
            {
                return 1;
            }

            st.pop();

            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    if (i < A.length() - 1)
                    {
                        if (A[i + 1] == ')')
                        {
                            return 1;
                        }
                        else
                        {
                            st.push('x');
                        }
                    }
                }
                else
                {
                    st.push('x');
                }
            }
        }
        else
        {
            st.push(A[i]);
        }
    }

    return 0;
}
```