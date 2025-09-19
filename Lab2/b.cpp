#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
    Node(const string &d) : data(d), next(nullptr) {}
};

class LinkedList
{
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const string &val)
    {
        Node *node = new Node(val);
        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void shift(int k)
    {
        if (!head || size == 0 || k % size == 0)
            return;
        k = k % size;
        Node *curr = head;
        for (int i = 1; i < k; ++i)
        {
            curr = curr->next;
        }
        Node *new_head = curr->next;
        curr->next = nullptr;
        tail->next = head;
        head = new_head;
        tail = curr;
    }

    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    ~LinkedList()
    {
        Node *curr = head;
        while (curr)
        {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    LinkedList list;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        list.push_back(s);
    }
    list.shift(K);
    list.print();
    return 0;
}