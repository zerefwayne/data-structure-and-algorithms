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
    int maxPathSumUtil(TreeNode *root, int &res)
    {

        if (root == NULL)
            return 0;

        int l = this->maxPathSumUtil(root->left, res);
        int r = this->maxPathSumUtil(root->right, res);

        int max_single = max(max(l, r) + root->val, root->val);

        int max_top = max(max_single, l + r + root->val);

        res = max(res, max_top);

        return max_single;
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
