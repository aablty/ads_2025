#include <iostream>
#include <string>
using namespace std;

void fill(string *&els, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> els[i];
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    string *els = new string[N];
    fill(els, N);

    for (int i = 0; i < N; i++)
    {
        cout << els[(i + K) % N] << " ";
    }

    return 0;
}