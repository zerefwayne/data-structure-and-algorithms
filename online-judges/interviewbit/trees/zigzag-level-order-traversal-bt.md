```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode *root)
{
    if (!root)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

void traverse(vector<vector<int>> &res, int level, int maxLevel, TreeNode *node)
{

    if (!node)
        return;

    if (level == maxLevel)
    {
        res[maxLevel].emplace_back(node->val);
        return;
    }

    if (maxLevel % 2 == 1)
    {

        traverse(res, level + 1, maxLevel, node->right);
        traverse(res, level + 1, maxLevel, node->left);
    }
    else
    {

        traverse(res, level + 1, maxLevel, node->left);
        traverse(res, level + 1, maxLevel, node->right);
    }
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *A)
{

    int levels = height(A);

    vector<vector<int>> res(levels);

    for (int i = 0; i < levels; i++)
    {
        traverse(res, 0, i, A);
    }

    return res;
}
```