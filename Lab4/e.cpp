#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *search(Node *root, int x)
{
    if (!root)
        return NULL;
    if (root->val == x)
        return root;
    Node *l = search(root->left, x);
    if (l)
        return l;
    return search(root->right, x);
}

Node *insert(Node *root, int x, int y, int z)
{
    Node *parent = search(root, x);
    if (!parent)
        return root;

    if (z == 0)
        parent->left = new Node(y);
    else
        parent->right = new Node(y);

    return root;
}

int getHeight(Node *root)
{
    if (!root)
        return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void widthOfLevels(Node *root, int widths[], int level = 0)
{
    if (!root)
        return;
    widths[level]++;
    widthOfLevels(root->left, widths, level + 1);
    widthOfLevels(root->right, widths, level + 1);
}

int main()
{
    int n;
    cin >> n;

    Node *root = new Node(1);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    int maxLevel = getHeight(root);
    int widths[1005] = {0};

    widthOfLevels(root, widths);

    int maxWidth = 0;
    for (int i = 0; i < maxLevel; i++)
    {
        if (widths[i] > maxWidth)
            maxWidth = widths[i];
    }

    cout << maxWidth;
    return 0;
}
