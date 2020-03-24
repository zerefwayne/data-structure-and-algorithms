[Leetcode Weekly Contest 98 - Tree from Preorder and Postorder](https://leetcode.com/contest/weekly-contest-98/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

## Approach 1: Recursive ACCEPTED

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *util(vector<int> &pre, vector<int> &post, int preL, int preR, int postL, int postR)
    {

        TreeNode *newNode = new TreeNode(pre[preL]);

        if (preL == preR)
        {
            return newNode;
        }

        if (pre[preL + 1] == post[postL + 1])
        {
            newNode->right = NULL;
            newNode->left = this->util(pre, post, preL + 1, preR, postL + 1, postR);
        }

        else
        {

            int rightPreL = find(pre.begin(), pre.end(), post[postL + 1]) - pre.begin();
            int rightPreR = preR;

            int leftPostL = postL + 1 + (preR - rightPreL + 1);
            int leftPostR = postR;

            int rightPostL = postL + 1;
            int rightPostR = leftPostL - 1;

            int leftPreL = preL + 1;
            int leftPreR = rightPreL - 1;

            newNode->left = util(pre, post, leftPreL, leftPreR, leftPostL, leftPostR);
            newNode->right = util(pre, post, rightPreL, rightPreR, rightPostL, rightPostR);
        }

        return newNode;
    }

    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {

        if (pre.size() == 0)
        {
            return NULL;
        }

        reverse(post.begin(), post.end());
        int N = pre.size();

        TreeNode *res = util(pre, post, 0, N - 1, 0, N - 1);

        return res;
    }
};
```

