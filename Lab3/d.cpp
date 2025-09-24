#include <iostream>
#include <algorithm>
using namespace std;

int lower_bound(int *arr, int n, int x)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int upper_bound(int *arr, int n, int x)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] <= x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < q; ++i)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int left1 = lower_bound(arr, n, l1);
        int right1 = upper_bound(arr, n, r1);
        int count1 = right1 - left1;

        int left2 = lower_bound(arr, n, l2);
        int right2 = upper_bound(arr, n, r2);
        int count2 = right2 - left2;

        int overlap = 0;
        int ol = max(l1, l2), orr = min(r1, r2);
        if (ol <= orr)
        {
            int lefto = lower_bound(arr, n, ol);
            int righto = upper_bound(arr, n, orr);
            overlap = righto - lefto;
        }

        cout << (count1 + count2 - overlap) << endl;
    }

    delete[] arr;
    return 0;
}
