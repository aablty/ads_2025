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

int subtreeSize(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

void getSize(Node *root, int x)
{
    if (root == NULL)
    {
        cout << 0 << endl;
        return;
    }
    if (root->val == x)
    {
        cout << subtreeSize(root) << endl;
        return;
    }

    if (x < root->val)
        getSize(root->left, x);
    else
        getSize(root->right, x);
}

int main()
{
    int N;
    cin >> N;
    Node *root = NULL;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int X;
    cin >> X;
    getSize(root, X);

    return 0;
}