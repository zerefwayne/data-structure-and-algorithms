## Approach 1: Recursion, Use Identical Binary Trees ACCEPTED

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
int isSameTree(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
    {
        return 1;
    }
    else if (A != NULL && B != NULL)
    {
        if (A->val == B->val)
        {
            return isSameTree(A->left, B->right) && isSameTree(A->right, B->left);
        }
    }
    return 0;
}

int Solution::isSymmetric(TreeNode *A)
{
    if (A == NULL)
    {
        return 1;
    }

    return isSameTree(A->left, A->right);
}
```