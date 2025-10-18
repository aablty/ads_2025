#include <iostream>
#include <string>
using namespace std;

int partition(string &s, int low, int high)
{
    char pivot = s[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (s[j] < pivot)
        {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void quickSort(string &s, int low, int high)
{
    if (low < high)
    {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main()
{
    string s;
    cin >> s;

    quickSort(s, 0, s.length() - 1);

    cout << s << endl;

    return 0;
}