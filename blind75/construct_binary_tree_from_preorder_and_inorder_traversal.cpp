#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using N = TreeNode;
using it = vector<int>::iterator;

N *construct(vector<int> &preorder, vector<int> &inorder, it p, it i_b, it i_e)
{
    if (i_b == i_e)
        return nullptr;
    N *root = new N(*p);
    it pivot = find(i_b, i_e, *p);
    root->left = construct(preorder, inorder, p + 1, i_b, pivot);
    root->right = construct(preorder, inorder, p + 1 + (pivot - i_b), pivot + 1, i_e);
    return root;
}

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return construct(preorder, inorder, preorder.begin(), inorder.begin(), inorder.end());
    }
};