#### Keep in mind the case where A is a multiple of 26

```cpp
string Solution::convertToTitle(int A)
{
    string res = "";
    while (A > 0)
    {
        int rem = A % 26;
        if (rem)
        {
            char c = rem - 1 + 'A';
            string s;
            s.push_back(c);
            res.insert(0, s);
            A = A / 26;
        }
        else
        {
            res.insert(0, "Z");
            A = A / 26 - 1;
        }
    }
    return res;
}
```