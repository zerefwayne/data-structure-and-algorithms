```cpp
vector<int> Solution::prevSmaller(vector<int> &A)
{

    vector<int> res(A.size());

    stack<int> st;

    for (int i = 0; i < A.size(); i++)
    {

        bool flag = false;

        while (!st.empty())
        {

            if (st.top() < A[i])
            {
                flag = true;
                break;
            }
            else
            {
                st.pop();
            }
        }

        if (!flag)
        {
            res[i] = -1;
        }
        else
        {
            res[i] = st.top();
        }

        st.push(A[i]);
    }

    return res;
}
```