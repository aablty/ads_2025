#include <iostream>
using namespace std;

struct Node
{
    string val;
    Node *next;
    Node() : val(""), next(nullptr) {}
    Node(string x) : val(x), next(nullptr) {}
    Node(Node *next) : val(""), next(next) {}
    Node(string x, Node *next) : val(x), next(next) {}
};

Node *add_front(Node *head, string str)
{
    Node *newNode = new Node(str);
    newNode->next = head;
    head = newNode;
    cout << "ok" << endl;
    return head;
}

Node *add_back(Node *head, string str)
{
    if (head == nullptr)
    {
        return add_front(head, str);
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    Node *newNode = new Node(str);
    current->next = newNode;
    cout << "ok" << endl;
    return head;
}

Node *erase_front(Node *head)
{
    if (head == nullptr)
    {
        cout << "error" << endl;
        return head;
    }

    Node *temp = head;
    head = head->next;
    cout << temp->val << endl;
    delete temp;
    return head;
}

Node *erase_back(Node *head)
{
    if (head == nullptr)
    {
        cout << "error" << endl;
        return head;
    }

    if (head->next == nullptr)
    {
        cout << head->val << endl;
        delete head;
        return nullptr;
    }

    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    cout << current->next->val << endl;
    delete current->next;
    current->next = nullptr;
    return head;
}

void back(Node *head)
{
    if (head == nullptr)
    {
        cout << "error" << endl;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    cout << current->val << endl;
}

void front(Node *head)
{
    if (head == nullptr)
    {
        cout << "error" << endl;
        return;
    }
    cout << head->val << endl;
}

Node *clear(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    cout << "ok" << endl;
    return nullptr;
}

int main()
{
    Node *head = nullptr;
    while (true)
    {
        string command;
        cin >> command;
        if (command == "exit")
        {
            cout << "goodbye" << endl;
            break;
        }
        else if (command == "add_front")
        {
            string str;
            cin >> str;
            head = add_front(head, str);
        }
        else if (command == "add_back")
        {
            string str;
            cin >> str;
            head = add_back(head, str);
        }
        else if (command == "erase_front")
        {
            head = erase_front(head);
        }
        else if (command == "erase_back")
        {
            head = erase_back(head);
        }
        else if (command == "front")
        {
            front(head);
        }
        else if (command == "back")
        {
            back(head);
        }
        else if (command == "clear")
        {
            head = clear(head);
        }
    }
    return 0;
}
