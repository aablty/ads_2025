#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);

    return root;
}

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;

    if (x < root->val)
        return search(root->left, x);
    else
        return search(root->right, x);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

bool checkPath(Node *root, const string &path)
{
    Node *current = root;
    for (char c : path)
    {
        if (c == 'L')
        {
            if (current->left)
                current = current->left;
            else
                return false;
        }
        else if (c == 'R')
        {
            if (current->right)
                current = current->right;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    for (int i = 0; i < M; i++)
    {
        string path;
        cin >> path;
        cout << (checkPath(root, path) ? "YES" : "NO") << "\n";
    }

    return 0;
}
