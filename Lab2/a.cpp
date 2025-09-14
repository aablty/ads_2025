#include <iostream>
using namespace std;

void fill(int *&els, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> els[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *els = new int[n];
    fill(els, n);
    int k;
    cin >> k;

    int nearest = 0;

    for (int i = 0; i < n; i++)
    {
        if (abs(els[i] - k) < abs(els[nearest] - k))
        {
            nearest = i;
        }
    }

    cout << nearest << endl;

    return 0;
}