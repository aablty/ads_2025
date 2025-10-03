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

void getTriangles(Node *root, int &triangles)
{
    if (root == NULL)
        return;
    if (root->left && root->right)
        triangles++;
    getTriangles(root->left, triangles);
    getTriangles(root->right, triangles);
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
    
    int triangles = 0;
    getTriangles(root, triangles);
    cout << triangles;

    return 0;
}