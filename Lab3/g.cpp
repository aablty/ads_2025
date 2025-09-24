#include <iostream>
using namespace std;

bool canDeliver(const int *c, int n, int f, int capacity)
{
    int flights = 0;
    for (int i = 0; i < n; ++i)
    {
        flights += (c[i] + capacity - 1) / capacity;
    }
    return flights <= f;
}

int main()
{
    int n, f;
    cin >> n >> f;
    int c[100005];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int max_c = c[0];
    for (int i = 1; i < n; ++i)
        if (c[i] > max_c)
            max_c = c[i];

    int left = 1, right = max_c;
    int answer = right;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canDeliver(c, n, f, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
