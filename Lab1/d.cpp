#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char *data;
    int size;
    int top;

public:
    Stack(int n)
    {
        data = new char[n];
        size = n;
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }

    void push(char x)
    {
        top++;
        data[top] = x;
    }

    char pop()
    {
        top--;
        return data[top + 1];
    }

    char getTop()
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

bool isBalanced(string S)
{
    Stack stack(S.length());

    for (int i = 0; i < S.length(); i++)
    {
        char c = S[i];

        if (stack.empty())
        {
            stack.push(c);
        }
        else
        {
            if (stack.getTop() == c)
            {
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }
    }

    return stack.empty();
}

int main()
{
    string S;
    cin >> S;

    isBalanced(S) ? cout << "YES" : cout << "NO";

    return 0;
}
