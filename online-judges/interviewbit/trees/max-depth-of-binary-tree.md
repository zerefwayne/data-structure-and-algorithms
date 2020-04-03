## Approach 1: Recursion ACCEPTED

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
int Solution::maxDepth(TreeNode *A)
{
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        return max(maxDepth(A->left), maxDepth(A->right)) + 1;
    }
}
```