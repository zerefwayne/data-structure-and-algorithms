## Approach 1

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

int isBalancedUtil(TreeNode *A)
{

    if (A == NULL)
    {
        return 0;
    }

    int left = isBalancedUtil(A->left);
    int right = isBalancedUtil(A->right);

    // Error encountered in a subtree

    if (left == -1 || right == -1)
    {
        return -1;
    }

    // No error encountered

    if (abs(left - right) > 1)
    {
        return -1;
    }
    else
    {
        return 1 + max(left, right);
    }
}

int Solution::isBalanced(TreeNode *A)
{

    return isBalancedUtil(A) == -1 ? 0 : 1;
}
```