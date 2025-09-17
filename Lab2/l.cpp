#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node()
    {
        val = 0;
        next = NULL;
    }
};

int findMaxSum(int n, Node *head)
{
    int maxSum = head->val;
    int currentSum = head->val;

    Node *current = head->next;

    while (current != NULL)
    {
        currentSum = max(current->val, currentSum + current->val);
        maxSum = max(maxSum, currentSum);
        current = current->next;
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    Node *head, *tail;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur->val = x;

        if (i == 1)
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}
