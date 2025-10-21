#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r, int tmp[])
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

void merge_sort(int a[], int l, int r, int tmp[])
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
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];

    int tmp1[n], tmp2[m];

    merge_sort(a1, 0, n, tmp1);
    merge_sort(a2, 0, m, tmp2);

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            cout << a1[i] << " ";
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << endl;
    return 0;
}
