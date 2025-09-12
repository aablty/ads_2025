#include <iostream>
using namespace std;

class Stack
{
private:
    int *data;
    int size;
    int top;

public:
    Stack(int n)
    {
        data = new int[n];
        size = n;
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }

    void push(int x)
    {
        top++;
        data[top] = x;
    }

    int pop()
    {
        top--;
        return data[top + 1];
    }

    int getTop()
    {
        return data[top];
    }

    bool empty()
    {
        return top == -1;
    }

    bool full()
    {
        return top == size - 1;
    }
};

int main()
{
    int n;
    cin >> n;
    int ages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ages[i];
    }

    Stack st(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && ages[st.getTop()] > ages[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            cout << -1;
        }
        else
        {
            cout << ages[st.getTop()];
        }

        if (i < n - 1)
        {
            cout << " ";
        }

        st.push(i);
    }
    cout << endl;

    return 0;
}