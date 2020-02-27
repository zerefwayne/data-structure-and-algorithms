#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree
{

    Node *root;

public:
    BinarySearchTree(int data)
    {
        this->root = new Node(data);
    }

    void insertNode(int data)
    {

        Node *temp = root;

        while (true)
        {

            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node(data);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (data > temp->data)
            {

                if (temp->right == NULL)
                {
                    temp->right = new Node(data);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                break;
            }
        }
    }

    void inorderTraversalUtil(Node *node)
    {

        if (node->left != NULL)
        {
            inorderTraversalUtil(node->left);
        }

        cout << node->data << ' ';

        if (node->right != NULL)
        {
            inorderTraversalUtil(node->right);
        }
    }

    void inorderTraversal(bool isIterative)
    {

        if (!isIterative)
        {
            cout << "Recursive Inorder Traversal: ";

            inorderTraversalUtil(this->root);

            cout << "\n\n";
        }
        else
        {
            cout << "Iterative Inorder Traversal: ";

            stack<Node *> travStack;
            vector<int> result;

            Node *temp = this->root;

            while (temp != NULL || !travStack.empty())
            {

                while (temp != NULL)
                {
                    travStack.emplace(temp);
                    temp = temp->left;
                }

                temp = travStack.top();
                travStack.pop();

                result.emplace_back(temp->data);

                temp = temp->right;
            }

            for (auto &node : result)
            {
                cout << node << ' ';
            }

            cout << "\n\n";
        }
    }

    int calculateHeight(Node *node)
    {
        if (node == NULL)
            return 0;

        int lHeight = calculateHeight(node->left);
        int rHeight = calculateHeight(node->right);

        return max(lHeight, rHeight) + 1;
    }

    void levelOrderTraversalUtil(Node *temp, int level)
    {
        if (temp == NULL)
            return;

        if (level == 0)
        {
            cout << temp->data << " ";
            return;
        }
        else
        {
            levelOrderTraversalUtil(temp->left, level - 1);
            levelOrderTraversalUtil(temp->right, level - 1);
        }
    }

    void levelOrderTraversal(bool isIterative)
    {
        if (!isIterative)
        {
            cout << "Recursive Level Order Traversal\n\n";

            int height = calculateHeight(this->root);

            for (int i = 0; i < height; i++)
            {
                cout << "Level " << i + 1 << ": ";
                levelOrderTraversalUtil(this->root, i);
                cout << '\n';
            }

            cout << '\n';
        }
        else
        {
            cout << "Iterative Level Order Traversal: ";

            queue<Node *> travStack;
            vector<int> result;

            travStack.emplace(this->root);

            while (!travStack.empty())
            {

                Node *temp = travStack.front();
                travStack.pop();

                result.emplace_back(temp->data);

                if (temp->left)
                    travStack.push(temp->left);
                if (temp->right)
                    travStack.push(temp->right);
            }

            for (auto &node : result)
            {
                cout << node << ' ';
            }

            cout << "\n\n";
        }
    }

    void preOrderTraversalUtil(Node *node)
    {

        if (node == NULL)
            return;

        cout << node->data << ' ';
        preOrderTraversalUtil(node->left);
        preOrderTraversalUtil(node->right);
    }

    void preOrderTraversal(bool isIterative)
    {

        if (isIterative)
        {

            cout << "Iterative Pre Order Traversal: ";

            stack<Node *> travStack;
            vector<int> result;

            travStack.emplace(this->root);

            while (!travStack.empty())
            {

                Node *top = travStack.top();
                travStack.pop();
                result.emplace_back(top->data);

                if (top->right)
                    travStack.push(top->right);
                if (top->left)
                    travStack.push(top->left);
            }

            for (auto &node : result)
            {
                cout << node << ' ';
            }

            cout << "\n\n";
        }
        else
        {
            cout << "Recursive Pre Order Traversal: ";

            this->preOrderTraversalUtil(this->root);

            cout << "\n\n";
        }
    }
};

int main()
{

    BinarySearchTree bst = BinarySearchTree(5);

    bst.insertNode(3);
    bst.insertNode(4);
    bst.insertNode(10);

    bst.levelOrderTraversal(false);

    bst.inorderTraversal(true);

    bst.levelOrderTraversal(true);

    bst.preOrderTraversal(false);
    bst.inorderTraversal(false);
    bst.preOrderTraversal(true);

    return 0;
}