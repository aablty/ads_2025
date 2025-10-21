#include <iostream>
using namespace std;

struct Row
{
    int arr[500];
    int sum;
    int idx;
};

bool isLess(const Row &a, const Row &b, int m)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    for (int i = 0; i < m; ++i)
    {
        if (a.arr[i] != b.arr[i])
            return a.arr[i] < b.arr[i];
    }
    return false;
}

void merge(Row a[], int l, int m, int r, Row tmp[], int mcols)
{
    int i = l, j = m, k = l;
    while (i < m && j < r)
    {
        if (isLess(a[i], a[j], mcols))
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i < m)
        tmp[k++] = a[i++];
    while (j < r)
        tmp[k++] = a[j++];
    for (int t = l; t < r; ++t)
        a[t] = tmp[t];
}

void merge_sort(Row a[], int l, int r, Row tmp[], int mcols)
{
    if (r - l <= 1)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid, tmp, mcols);
    merge_sort(a, mid, r, tmp, mcols);
    merge(a, l, mid, r, tmp, mcols);
}

int main()
{
    int n, m;
    cin >> n >> m;

    Row rows[500];
    Row tmp[500];

    for (int i = 0; i < n; ++i)
    {
        rows[i].sum = 0;
        for (int j = 0; j < m; ++j)
        {
            cin >> rows[i].arr[j];
            rows[i].sum += rows[i].arr[j];
        }
    }

    merge_sort(rows, 0, n, tmp, m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << rows[i].arr[j];
            if (j + 1 < m)
                cout << " ";
        }
        cout << " \n";
    }

    return 0;
}
