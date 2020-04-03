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
    int heightOfTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
    }

    void traverseLevel(int curr, int level, TreeNode *root, vector<vector<int>> &levels)
    {
        if (root == NULL)
            return;
        if (curr == level)
        {
            levels[level].emplace_back(root->val);
            return;
        }
        traverseLevel(curr + 1, level, root->left, levels);
        traverseLevel(curr + 1, level, root->right, levels);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {

        int height = heightOfTree(root);
        vector<vector<int>> levels(height);

        for (int i = 0; i < height; i++)
        {
            traverseLevel(0, i, root, levels);
        }

        return levels;
    }
};