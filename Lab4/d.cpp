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

void sumOfLevels(Node *root, int level, int *sums)
{
    if (root == NULL)
        return;
    sums[level] += root->val;
    sumOfLevels(root->left, level + 1, sums);
    sumOfLevels(root->right, level + 1, sums);
}

int getMaxLevel(Node *root)
{
    if (root == NULL)
        return 0;
    int leftLevel = getMaxLevel(root->left);
    int rightLevel = getMaxLevel(root->right);
    return 1 + (leftLevel > rightLevel ? leftLevel : rightLevel);
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

    int maxLevel = getMaxLevel(root);
    cout << maxLevel << endl;

    int sums[5001] = {0};
    sumOfLevels(root, 0, sums);
    for (int i = 0; i < maxLevel; ++i)
        cout << sums[i] << (i == maxLevel - 1 ? '\n' : ' ');

    return 0;
}