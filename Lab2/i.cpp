#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(Node *next) : val(0), next(next) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node *insert(Node *head, Node *node, int p)
{
    if (p == 0)
    {
        node->next = head;
        return node;
    }

    Node *current = head;
    for (int i = 0; i < p - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        return head;
    }

    node->next = current->next;
    current->next = node;
    return head;
}

Node *remove(Node *head, int p)
{
    if (head == nullptr || p < 0)
    {
        return head;
    }

    if (p == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *current = head;
    for (int i = 0; i < p - 1 && current->next != nullptr; i++)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        return head;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    return head;
}

Node *replace(Node *head, int p1, int p2)
{
    if (head == nullptr || p1 < 0 || p2 < 0 || (p1 == p2))
    {
        return head;
    }

    Node *nodeToMove = nullptr;
    if (p1 == 0)
    {
        nodeToMove = head;
        head = head->next;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < p1 - 1; i++)
        {
            current = current->next;
        }
        nodeToMove = current->next;
        current->next = nodeToMove->next;
    }

    if (p2 == 0)
    {
        nodeToMove->next = head;
        head = nodeToMove;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < p2 - 1; i++)
        {
            current = current->next;
        }
        nodeToMove->next = current->next;
        current->next = nodeToMove;
    }

    return head;
}

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void print(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->val;
        if (current->next != nullptr)
        {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

Node *cyclic_left(Node *head, int x)
{
    if (head == nullptr || x <= 0)
    {
        return head;
    }

    Node *tail = head;
    int length = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        length++;
    }

    x = x % length;
    if (x == 0)
    {
        return head;
    }

    Node *newTail = head;
    for (int i = 0; i < x - 1; i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

Node *cyclic_right(Node *head, int x)
{
    if (head == nullptr || x <= 0)
    {
        return head;
    }

    Node *tail = head;
    int length = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        length++;
    }

    x = x % length;
    if (x == 0)
    {
        return head;
    }

    Node *newTail = head;
    for (int i = 0; i < length - x - 1; i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

int main()
{
    Node *head = nullptr;
    while (true)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            break;
        }
        else if (command == 1)
        {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2)
        {
            int p;
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3)
        {
            print(head);
        }
        else if (command == 4)
        {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5)
        {
            head = reverse(head);
        }
        else if (command == 6)
        {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7)
        {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}
