#include <iostream>
#include <climits>
using namespace std;

void merge(long long a[], int l, int m, int r, long long tmp[])
{
    int i = l, j = m, k = l;
    while (i < m && j < r)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i < m)
        tmp[k++] = a[i++];
    while (j < r)
        tmp[k++] = a[j++];
    for (int t = l; t < r; ++t)
        a[t] = tmp[t];
}

void merge_sort(long long a[], int l, int r, long long tmp[])
{
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    merge_sort(a, l, m, tmp);
    merge_sort(a, m, r, tmp);
    merge(a, l, m, r, tmp);
}

int main()
{
    int n;
    cin >> n;
    if (n < 2)
        return 0;

    long long *a = new long long[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long *tmp = new long long[n];
    merge_sort(a, 0, n, tmp);

    long long minDiff = LLONG_MAX;
    for (int i = 0; i + 1 < n; ++i)
        if (a[i + 1] - a[i] < minDiff)
            minDiff = a[i + 1] - a[i];

    bool first = true;
    for (int i = 0; i + 1 < n; ++i)
    {
        if (a[i + 1] - a[i] == minDiff)
        {
            if (!first)
                cout << ' ';
            cout << a[i] << ' ' << a[i + 1];
            first = false;
        }
    }
    cout << '\n';

    delete[] a;
    delete[] tmp;
}
