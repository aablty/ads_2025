#include <iostream>
using namespace std;

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool customCompare(char a, char b)
{
    if (!isVowel(a) && isVowel(b))
        return true;
    if (isVowel(a) && !isVowel(b))
        return false;
    return a > b;
}

void heapify(char arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && customCompare(arr[l], arr[largest]))
        largest = l;
    if (r < n && customCompare(arr[r], arr[largest]))
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(char arr[], int n)
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
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;

    return 0;
}