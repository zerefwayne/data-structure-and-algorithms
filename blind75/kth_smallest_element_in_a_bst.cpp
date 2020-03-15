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

    vector<int> inorder;

public:
    void traverseInorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        this->traverseInorder(root->left);
        inorder.emplace_back(root->val);
        this->traverseInorder(root->right);
    }

    int kthSmallestIterative(TreeNode *root, int k)
    {

        stack<TreeNode *> rootStack;
        TreeNode *temp = root;

        while (true)
        {

            while (temp)
            {
                rootStack.push(temp);
            }

            temp = rootStack.top();
            rootStack.pop();
            k--;
            if (k == 0)
            {
                return temp->val;
            }

            temp = temp->right;
        }
    }

    int kthSmallest(TreeNode *root, int k)
    {

        // Approach 1: RECURSIVE APPROACH: Build a complete inorder traversal and return k-1th element
        //  this->traverseInorder(root);
        //  return this->inorder[k - 1];

        // Approach 2: ITERATIVE APPROACH: No need to build an entire traversal
        // Gives result in half the runtime of recursive approach

            return this->kthSmallestIterative(root, k);
    }
};