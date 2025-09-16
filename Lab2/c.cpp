#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    Node *get_head() const
    {
        return head;
    }

    Node *get_tail() const
    {
        return tail;
    }

    void set_head(Node *new_head)
    {
        head = new_head;
    }
    void set_tail(Node *new_tail)
    {
        tail = new_tail;
    }

    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (!head)
            return;
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_back()
    {
        if (!tail)
            return;
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void print_forward()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void print_backward()
    {
        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        while (head)
            pop_front();
    }
};

void fill(LinkedList &list, int N)
{
    for (int i = 0; i < N; ++i)
    {
        int value;
        cin >> value;
        list.push_back(value);
    }
}

int main()
{
    int N;
    cin >> N;
    LinkedList list;
    fill(list, N);

    Node *current = list.get_head();
    int position = 0;
    while (current)
    {
        Node *next = current->next;
        if (position % 2 == 1)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                list.set_head(current->next);
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                list.set_tail(current->prev);
            }
            delete current;
        }
        current = next;
        position++;
    }

    list.print_forward();

    return 0;
}