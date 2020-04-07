```cpp
string Solution::countAndSay(int A)
{

    string str = "1";

    int i = 1;
    char curr = '1';
    int count = 0;

    while (i < A)
    {

        count = 0;
        curr = str[0];
        string next_str = "";

        for (int j = 0; j < str.length(); j++)
        {

            if (str[j] == curr)
            {
                count++;
            }
            else
            {
                next_str += to_string(count);
                next_str.push_back(curr);
                count = 1;
                curr = str[j];
            }
        }

        next_str += to_string(count);
        next_str.push_back(curr);

        str = next_str;
        i++;
    }

    return str;
}
```