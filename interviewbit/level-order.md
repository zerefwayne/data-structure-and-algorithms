# Approach 1: Iterative BFS using a single Queue

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

vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    queue<TreeNode *> travQueue;

    vector<vector<int>> res;

    if (A == NULL)
    {
        return res;
    }

    travQueue.push(A);
    travQueue.push(NULL);
    vector<int> row;

    while (travQueue.size() > 1)
    {

        TreeNode *top = travQueue.front();
        travQueue.pop();

        if (top == NULL)
        {
            res.emplace_back(row);
            row.clear();
            travQueue.push(NULL);
            continue;
        }

        row.emplace_back(top->val);

        if (top->left != NULL)
        {
            travQueue.push(top->left);
        }

        if (top->right != NULL)
        {
            travQueue.push(top->right);
        }
    }

    res.emplace_back(row);

    return res;
}
```