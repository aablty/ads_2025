#include <iostream>
#include <string>
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
    string str1, str2;
    cin >> str1 >> str2;

    Stack st1(100000);
    Stack st2(100000);

    for (char ch : str1)
    {
        if (ch == '#')
            st1.pop();
        else
            st1.push(ch);
    }
    for (char ch : str2)
    {
        if (ch == '#')
            st2.pop();
        else
            st2.push(ch);
    }

    string res1, res2;
    while (!st1.empty())
        res1 += st1.pop();

    while (!st2.empty())
        res2 += st2.pop();

    cout << (res1 == res2 ? "Yes" : "No");

    return 0;
}