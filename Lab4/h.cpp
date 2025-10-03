#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int x, Node *p = NULL) : val(x), left(NULL), right(NULL), parent(p) {}
};

Node *insert(Node *root, int x, Node *parent = NULL)
{
    if (root == NULL)
        return new Node(x, parent);

    if (x < root->val)
        root->left = insert(root->left, x, root);
    else if (x > root->val)
        root->right = insert(root->right, x, root);

    return root;
}

void greaterSumTree(Node *root, int &sum)
{
    if (root == NULL)
        return;
    greaterSumTree(root->right, sum);
    sum += root->val;
    root->val = sum;
    greaterSumTree(root->left, sum);
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;
    inOrderPrint(root->right);
    cout << root->val << " ";
    inOrderPrint(root->left);
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
    int sum = 0;
    greaterSumTree(root, sum);
    inOrderPrint(root);

    return 0;
}
