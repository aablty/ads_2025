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

void print(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

void getGifts(Node *root, int x)
{
    if (root == NULL)
    {
        cout << 0 << endl;
        return;
    }
    if (root->val == x)
    {
        print(root);
        return;
    }

    if (x < root->val)
        getGifts(root->left, x);
    else
        getGifts(root->right, x);
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int k;
    cin >> k;
    getGifts(root, k);

    return 0;
}