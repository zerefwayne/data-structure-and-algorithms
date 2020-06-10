```cpp
void inorderTree(TreeNode *node, int &k, int &smallest, int B)
{

    if (node == NULL)
    {
        return;
    }

    inorderTree(node->left, k, smallest, B);

    k++;

    if (k == B && smallest == INT_MAX)
    {
        smallest = node->val;
        return;
    }

    inorderTree(node->right, k, smallest, B);
}

int Solution::kthsmallest(TreeNode *A, int B)
{

    int smallest = INT_MAX;
    int k = 0;
    inorderTree(A, k, smallest, B);
    return smallest;
}
```