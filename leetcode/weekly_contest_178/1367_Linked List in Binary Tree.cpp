#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isSubPathUtil(ListNode *head, ListNode *temp, TreeNode *root)
    {

        bool left = false;
        bool right = false;

        if (temp->val == root->val)
        {
            temp = temp->next;
        }
        else if (head->val == root->val)
        {
            temp = head->next;
        }
        else
        {
            temp = head;
        }

        if (temp == NULL)
        {
            return true;
        }

        if (root->left)
        {
            left = this->isSubPathUtil(head, temp, root->left);
        }

        if (root->right)
        {
            right = this->isSubPathUtil(head, temp, root->right);
        }

        return left || right;
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {

        return this->isSubPathUtil(head, head, root);
    }
};

class Solution2
{
public:
    bool dfs(ListNode *head, TreeNode *root)
    {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;
        if (head->val == root->val)
        {
            return dfs(head->next, root->right) || dfs(head->next, root->left);
        }
        return false;
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == NULL)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};