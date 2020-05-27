```cpp
bool hasSumHelper(TreeNode *node, int current, int required)
{

    if (!node)
        return false;

    int updated = current + node->val;

    if (!node->left && !node->right)
    {

        if (updated == required)
        {
            return true;
        }

        if (updated > required)
        {
            return false;
        }
    }

    bool left = hasSumHelper(node->left, updated, required);
    bool right = hasSumHelper(node->right, updated, required);

    return left || right;
}

int Solution::hasPathSum(TreeNode *A, int B)
{

    return hasSumHelper(A, 0, B);
}
```