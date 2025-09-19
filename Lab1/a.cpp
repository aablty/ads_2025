#include <iostream>

using namespace std;

class Deque
{
private:
    int *data;
    int capacity;
    int front;
    int rear;
    int size;

    void resize()
    {
        int newCap = capacity * 2;
        int *newData = new int[newCap];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCap;
        front = 0;
        rear = size;
    }

public:
    Deque(int cap = 8)
    {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~Deque()
    {
        delete[] data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void push_back(int val)
    {
        if (size == capacity)
            resize();
        data[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }

    void push_front(int val)
    {
        if (size == capacity)
            resize();
        front = (front - 1 + capacity) % capacity;
        data[front] = val;
        size++;
    }

    int pop_back()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        rear = (rear - 1 + capacity) % capacity;
        int val = data[rear];
        size--;
        return val;
    }

    int pop_front()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        int val = data[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    int peek_front()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        return data[front];
    }

    int peek_back()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        return data[(rear - 1 + capacity) % capacity];
    }

    // Добавляем метод для доступа по индексу
    int operator[](int index)
    {
        if (index < 0 || index >= size)
            throw runtime_error("Index out of bounds!");
        return data[(front + index) % capacity];
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Deque deck(n * 2);

        for (int card = n; card >= 1; card--)
        {
            deck.push_front(card);

            for (int moves = 0; moves < card; moves++)
            {
                int back_card = deck.pop_back();
                deck.push_front(back_card);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << deck[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}