#include <iostream>
#include <string>
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
};

int main()
{
    Deque dq;
    Deque results;

    char c;
    while (cin >> c && c != '!')
    {
        switch (c)
        {
        case '+':
            int n1;
            cin >> n1;
            dq.push_front(n1);
            break;
        case '-':
            int n2;
            cin >> n2;
            dq.push_back(n2);
            break;
        case '*':
            if (dq.isEmpty())
                results.push_back(-1);
            else
            {
                results.push_back(dq.getSize() > 1 ? dq.pop_front() + dq.pop_back() : dq.pop_front() * 2);
            }
            break;
        }
    }
    while (!results.isEmpty())
    {
        int result = results.pop_front();
        result == -1 ? cout << "error" << endl : cout << result << endl;
    }
}