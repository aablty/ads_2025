#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long a[100000];

    long long low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > low)
            low = a[i];
        high += a[i];
    }

    auto can = [&](long long mid)
    {
        int blocks = 1;
        long long current = 0;
        for (int i = 0; i < n; i++)
        {
            if (current + a[i] > mid)
            {
                blocks++;
                current = a[i];
            }
            else
            {
                current += a[i];
            }
        }
        return blocks <= k;
    };

    while (low < high)
    {
        long long mid = (low + high) / 2;
        if (can(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
