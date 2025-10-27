#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    bool first = true;

    if (n % 2 == 0)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            count++;
            n /= 2;
        }
        cout << 2;
        if (count > 1)
            cout << "^" << count;
        first = false;
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            if (!first)
                cout << "*";
            cout << i;
            if (count > 1)
                cout << "^" << count;
            first = false;
        }
    }

    if (n > 1)
    {
        if (!first)
            cout << "*";
        cout << n;
    }

    cout << "\n";

    return 0;
}