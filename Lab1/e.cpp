#include <iostream>
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

void fillQueue(Queue &q, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.tail_enqueue(x);
    }
}

void checkCards(Queue &boris, Queue &nursik, int &moves)
{

    if (boris.isEmpty())
    {
        cout << "Nursik " << moves << endl;
        exit(0);
    }
    else if (nursik.isEmpty())
    {
        cout << "Boris " << moves << endl;
        exit(0);
    }

    int borisCard = boris.head_dequeue();
    int nursikCard = nursik.head_dequeue();
    moves++;

    if (borisCard == 0 && nursikCard == 9)
    {
        boris.tail_enqueue(borisCard);
        boris.tail_enqueue(nursikCard);
    }
    else if (nursikCard == 0 && borisCard == 9)
    {
        nursik.tail_enqueue(borisCard);
        nursik.tail_enqueue(nursikCard);
    }
    else if (borisCard > nursikCard)
    {
        boris.tail_enqueue(borisCard);
        boris.tail_enqueue(nursikCard);
    }
    else if (nursikCard > borisCard)
    {
        nursik.tail_enqueue(borisCard);
        nursik.tail_enqueue(nursikCard);
    }
}

int main()
{
    Queue boris(10);
    Queue nursik(10);
    fillQueue(boris, 5);
    fillQueue(nursik, 5);

    int moves = 0;

    while (moves < 1000000)
    {
        checkCards(boris, nursik, moves);
    }

    cout << "blin nichya" << endl;

    return 0;
}