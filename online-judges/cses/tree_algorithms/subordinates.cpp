/*

    Problem Link: https://cses.fi/problemset/task/1674
    Name: Subordinates
    Topic: Tree Algorithms

    Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

    Input

    The first input line has an integer n: the number of employees. The employees are numbered 1,2,…,n, and employee 1 is the general director of the company.

    After this, there are n−1 integers: for each employee 2,3,…,n their direct boss in the company.

    Output

    Print n integers: for each employee 1,2,…,n the number of their subordinates.

    Constraints
    1≤n≤2⋅105
    Example

    Input:
    5
    1 1 2 3

    Output:
    4 1 1 0 0

*/

/*
    Approach 1: Create a normal tree and store the hierarchy. Do a recursive DFS, store count_children + 1 in the array.
                O(n) time complexity. O(n) space complexity (ignoring call stack size)
                TIME LIMIT EXCEEDED

    Approach 2: Apply a DP Approach. Start traversing from right -> left and in the manager's column add current node count + 1
                O(n) time complexity. O(n) space complexity.
                TIME LIMIT EXCEEDED

    


*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{

    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    };
};

class Tree
{

    Node *root;
    int no_of_employees;

public:
    Tree(int no_of_employees)
    {
        this->root = new Node(1);
        this->no_of_employees = no_of_employees;
    }

    void addSubordinate(int data, int target)
    {

        queue<Node *> visitStack;
        visitStack.push(this->root);

        while (!visitStack.empty())
        {

            Node *top = visitStack.front();
            visitStack.pop();

            if (top->data == target)
            {
                top->children.emplace_back(new Node(data));
                break;
            }
            else
            {
                for (auto &child : top->children)
                {
                    visitStack.push(child);
                }
            }
        }
    }

    int countSubordinatesUtil(Node *node, vector<int> &subordinates)
    {

        if (node == NULL)
        {
            return 0;
        }

        int count = 0;

        for (auto &child : node->children)
        {
            count += countSubordinatesUtil(child, subordinates);
        }

        subordinates[node->data] = count;

        return count + 1;
    }

    void printSubordinatesDFS()
    {

        vector<int> subordinates(this->no_of_employees + 1, 0);

        this->countSubordinatesUtil(this->root, subordinates);

        for (int i = 1; i <= this->no_of_employees; i++)
        {

            cout << subordinates[i] << ' ';
        }

        cout << '\n';
    }

    void printSubordinatesDP(vector<int> &managerList)
    {

        vector<int> subordinates(this->no_of_employees + 1, 0);

        for (int i = managerList.size() - 1; i > 1; i--)
        {
            subordinates[managerList[i]] += subordinates[i] + 1;
        }

        for (int i = 1; i <= this->no_of_employees; i++)
        {
            cout << subordinates[i] << ' ';
        }

        cout << '\n';
    }
};

int main()
{

    int no_of_employees;
    cin >> no_of_employees;

    vector<int> managerList(no_of_employees + 1, 0);

    managerList[1] = -1;

    Tree tree(no_of_employees);

    /*
    
    APPROACH 1 MAIN CODE: TLE

    for (int i = 2; i <= no_of_employees; i++)
    {
        int manager;
        cin >> manager;
        tree.addSubordinate(i, manager);
    }

    tree.printSubordinatesDFS();

    */

    /*

    APPROACH 2 MAIN CODE: TLE
    
    for (int i = 2; i <= no_of_employees; i++)
    {
        int manager;
        cin >> manager;
        managerList[i] = manager;
    }

    tree.printSubordinatesDP(managerList);

    */

    return 0;
}