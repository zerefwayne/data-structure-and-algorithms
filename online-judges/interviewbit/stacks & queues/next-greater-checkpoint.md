```cpp
vector<int> Solution::nextGreater(vector<int> &A)
{

    reverse(A.begin(), A.end());

    vector<int> res(A.size(), -1);

    stack<int> st;

    for (int i = 0; i < A.size(); i++)
    {

        bool flag = false;

        while (!st.empty())
        {

            if (st.top() > A[i])
            {
                flag = true;
                break;
            }
            else
            {
                st.pop();
            }
        }

        if (flag)
        {
            res[i] = st.top();
        }
        else
        {
            res[i] = -1;
        }

        st.push(A[i]);
    }

    reverse(res.begin(), res.end());

    return res;
}
```