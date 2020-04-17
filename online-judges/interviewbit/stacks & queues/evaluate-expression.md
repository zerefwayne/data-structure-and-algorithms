```cpp
int Solution::evalRPN(vector<string> &A)
{

    stack<int> eval;

    for (int i = 0; i < A.size(); i++)
    {

        if (A[i] == "-" || A[i] == "/" || A[i] == "+" || A[i] == "*")
        {

            int b = eval.top();
            eval.pop();
            int a = eval.top();
            eval.pop();

            if (A[i] == "-")
            {
                eval.push(a - b);
            }
            else if (A[i] == "+")
            {
                eval.push(a + b);
            }
            else if (A[i] == "*")
            {
                eval.push(a * b);
            }
            else if (A[i] == "/")
            {
                eval.push(a / b);
            }
        }
        else
        {

            eval.push(stoi(A[i]));
        }
    }

    return eval.top();
}
```