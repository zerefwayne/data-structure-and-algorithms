#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isValidBSTUtil(TreeNode *root, int l, int r)
    {

        if (root == NULL)
        {
            return true;
        }

        if (root->val > l && root->val < r)
        {
            return isValidBSTUtil(root->left, l, root->val) && isValidBSTUtil(root->right, root->val, r);
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBSTUtil(root, INT_MIN, INT_MAX);
    }
};