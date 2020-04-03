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
    TreeNode *lcaRecursive(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return NULL;

        int rootVal = root->val;

        int pVal = p->val;
        int qVal = q->val;

        if (pVal > rootVal && qVal > rootVal)
        {
            return this->lcaRecursive(root->right, p, q);
        }
        else if (pVal < rootVal && qVal < rootVal)
        {
            return this->lcaRecursive(root->left, p, q);
        }
        else
        {
            return root;
        }
    }

    TreeNode *lcaIterative(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        TreeNode *node = root;
        int pVal = p->val;
        int qVal = q->val;

        while (node != NULL)
        {

            int rootVal = node->val;

            if (pVal > rootVal && qVal > rootVal)
            {
                node = node->right;
            }
            else if (pVal < rootVal && qVal < rootVal)
            {
                node = node->left;
            }
            else
            {
                return node;
            }
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Approach 1: Recursive Approach: ACCEPTED
        //      return this->lcaRecursive(root, p, q);

        // Approach 2: Iterative Approach: ACCEPTED
        return this->lcaIterative(root, p, q);
    }
};