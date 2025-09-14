#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;

    int head;
    int tail;

    bool full;
    bool empty;

public:
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;

        head = 0;
        tail = 0;

        full = false;
        empty = true;
    }
    ~Queue()
    {
        delete[] arr;
    }

    void print()
    {
        int i = head;

        if (tail == head && full)
        {
            cout << arr[i] << " ";
            if (i == size - 1)
                i = 0;
            else
                i++;
        }

        while (i != tail)
        {
            cout << arr[i] << " ";
            if (i == size - 1)
                i = 0;
            else
                i++;
        }

        cout << endl;
    }

    void tail_enqueue(int insertedItem)
    {
        empty = false;

        if (!full)
        {
            arr[tail] = insertedItem;
            if (tail == size - 1)
            {
                tail = 0;
            }
            else
            {
                tail++;
            }

            if (tail == head)
            {
                full = true;
            }
        }
        else
        {
            cout << "queue is full!" << endl;
        }
    }

    int head_dequeue()
    {
        full = false;
        int removedItem;

        if (!empty)
        {
            removedItem = arr[head];
            if (head == size - 1)
                head = 0;
            else
                head++;

            if (head == tail)
                empty = true;
        }
        else
        {
            cout << "queue is empty!" << endl;
        }

        return removedItem;
    }

    void head_enqueue(int insertedItem)
    {
        empty = false;

        if (!full)
        {
            if (head == 0)
            {
                head = size - 1;
            }
            else
            {
                head--;
            }

            arr[head] = insertedItem;

            if (head == tail)
            {
                full = true;
            }
        }
        else
        {
            cout << "queue is full!" << endl;
        }
    }

    int tail_dequeue()
    {
        full = false;
        int removedItem;

        if (!empty)
        {
            if (tail == 0)
            {
                tail = size - 1;
            }
            else
            {
                tail--;
            }

            removedItem = arr[tail];

            if (tail == head)
            {
                empty = true;
            }
        }
        else
        {
            cout << "queue is empty" << endl;
        }
        return removedItem;
    }

    bool isFull()
    {
        return full;
    }
    bool isEmpty()
    {
        return empty;
    }
};

void fillFractions(Queue &qSakayanagi, Queue &qKatsuragi, string &_class, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (_class[i] == 'S')
            qSakayanagi.tail_enqueue(i);
        else
            qKatsuragi.tail_enqueue(i);
    }
}

int main()
{
    int n;
    cin >> n;
    string _class;
    cin >> _class;

    Queue qSakayanagi(n);
    Queue qKatsuragi(n);
    fillFractions(qSakayanagi, qKatsuragi, _class, n);

    while (!qSakayanagi.isEmpty() && !qKatsuragi.isEmpty())
    {
        int iS = qSakayanagi.head_dequeue();
        int iK = qKatsuragi.head_dequeue();
        if (iS < iK)
            qSakayanagi.tail_enqueue(iS + n);
        else
            qKatsuragi.tail_enqueue(iK + n);
    }

    if (qSakayanagi.isEmpty())
        cout << "KATSURAGI";
    else
        cout << "SAKAYANAGI";

    return 0;
}