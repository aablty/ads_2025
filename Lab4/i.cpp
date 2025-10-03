#include <iostream>
using namespace std;

struct Node
{
    int val;
    int multiplicity = 1;
    Node *left;
    Node *right;
    Node *parent;

    Node(int x, Node *p = NULL) : val(x), left(NULL), right(NULL), parent(p) {}
};

Node *insert(Node *root, int x, Node *parent = NULL)
{
    if (root == NULL)
        return new Node(x, parent);
    if (root->val == x)
    {
        root->multiplicity++;
        return root;
    }
    if (x < root->val)
        root->left = insert(root->left, x, root);
    else if (x > root->val)
        root->right = insert(root->right, x, root);

    return root;
}

Node *findMin(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

Node *erase(Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x < root->val)
    {
        root->left = erase(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = erase(root->right, x);
    }
    else
    {
        if (root->multiplicity > 1)
        {
            root->multiplicity--;
            return root;
        }
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *minNode = findMin(root->right);
            root->val = minNode->val;
            root->multiplicity = minNode->multiplicity;
            minNode->multiplicity = 1;
            root->right = erase(root->right, minNode->val);
        }
    }
    return root;
}

int count(Node *root, int x)
{
    if (root == NULL)
        return 0;
    if (root->val == x)
        return root->multiplicity;

    if (x < root->val)
        return count(root->left, x);
    else
        return count(root->right, x);
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string cmd;
        int x;
        cin >> cmd >> x;

        static Node *root = NULL;

        if (cmd == "insert")
        {
            root = insert(root, x);
        }
        else if (cmd == "delete")
        {
            root = erase(root, x);
        }
        else if (cmd == "cnt")
        {
            cout << count(root, x) << "\n";
        }
    }

    return 0;
}
