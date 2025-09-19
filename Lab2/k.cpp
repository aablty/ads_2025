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
        int removedItem = -1;

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

    int getHead()
    {
        if (!empty)
            return arr[head];
        else
            return -1;
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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        char *arr = new char[N];
        int freq[256] = {0};
        Queue q(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            freq[(unsigned char)arr[i]]++;
            q.tail_enqueue((unsigned char)arr[i]);

            while (!q.isEmpty() && freq[q.getHead()] > 1)
            {
                q.head_dequeue();
            }

            if (q.isEmpty())
                cout << -1 << " ";
            else
                cout << (char)q.getHead() << " ";
        }
        cout << endl;
        delete[] arr;
    }
    return 0;
}
