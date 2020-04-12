```cpp
class Solution
{

    unordered_map<string, char> umap;

public:
    string entityParser(string text)
    {

        umap["&quot;"] = '\"';
        umap["&gt;"] = '>';
        umap["&lt;"] = '<';
        umap["&apos;"] = '\'';
        umap["&frasl;"] = '/';
        umap["&amp;"] = '&';

        string res = "";

        for (int i = 0; i < text.length(); i++)
        {

            if (text[i] == '&')
            {

                int j = i + 1;

                while (text[j] != ';' && j < text.length())
                {
                    j++;
                }

                if (j == text.length())
                {

                    if (text[j - 1] == ';')
                    {

                        string cmd = text.substr(i, j - i);

                        if (umap.find(cmd) != umap.end())
                        {
                            res.push_back(umap[cmd]);
                        }
                        else
                        {
                            res += cmd;
                        }

                        i = j;
                    }
                    else
                    {

                        while (i < text.length())
                        {
                            res.push_back(text[i]);
                            i++;
                        }
                    }
                }
                else
                {

                    if (text[j] == ';')
                    {

                        string cmd = text.substr(i, j - i + 1);

                        if (umap.find(cmd) != umap.end())
                        {
                            res.push_back(umap[cmd]);
                        }
                        else
                        {
                            res += cmd;
                        }

                        i = j;
                    }
                    else
                    {

                        while (i <= j)
                        {
                            res.push_back(text[i]);
                            i++;
                        }
                    }
                }
            }
            else
            {
                res.push_back(text[i]);
            }
        }

        return res;
    }
};
```