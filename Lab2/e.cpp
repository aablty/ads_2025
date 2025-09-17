#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
    string *data;
    int capacity;
    int front;
    int rear;
    int size;

    void resize()
    {
        int newCap = capacity * 2;
        string *newData = new string[newCap];

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
        data = new string[capacity];
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

    void push_back(string val)
    {
        if (size == capacity)
            resize();
        data[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }

    void push_front(string val)
    {
        if (size == capacity)
            resize();
        front = (front - 1 + capacity) % capacity;
        data[front] = val;
        size++;
    }

    string pop_back()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        rear = (rear - 1 + capacity) % capacity;
        string val = data[rear];
        size--;
        return val;
    }

    string pop_front()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        string val = data[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    string peek_front()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        return data[front];
    }

    string peek_back()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty!");
        return data[(rear - 1 + capacity) % capacity];
    }
};

int fillAndGetUniques(Deque &deq)
{
    string name;
    int count = 0;
    while (cin >> name)
    {
        if (deq.isEmpty())
        {
            deq.push_back(name);
            count++;
        }
        else
        {
            if (name != deq.peek_back())
            {
                deq.push_back(name);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    Deque deq;
    int count = fillAndGetUniques(deq);

    cout << "All in all: " << count << endl;
    cout << "Students:" << endl;
    while (!deq.isEmpty())
        cout << deq.pop_back() << endl;

    return 0;
}