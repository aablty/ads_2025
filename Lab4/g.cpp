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

int diameter = 0;
int height(Node *root)
{
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, lh + rh + 1);
    return max(lh, rh) + 1;
}

int main()
{
    int N;
    cin >> N;
    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    height(root);
    cout << diameter << endl;

    return 0;
}
