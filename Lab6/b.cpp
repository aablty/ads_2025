#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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

    heapSort(a1, n);
    heapSort(a2, m);

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