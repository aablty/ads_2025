#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Element
{
    string str;
    int len;
    int idx;
};

void merge(Element a[], int l, int m, int r, Element tmp[])
{
    int i = l, j = m, k = l;
    while (i < m && j < r)
    {
        if (a[i].len < a[j].len)
            tmp[k++] = a[i++];
        else if (a[i].len > a[j].len)
            tmp[k++] = a[j++];
        else
            tmp[k++] = (a[i].idx < a[j].idx ? a[i++] : a[j++]);
    }
    while (i < m)
        tmp[k++] = a[i++];
    while (j < r)
        tmp[k++] = a[j++];
    for (int t = l; t < r; ++t)
        a[t] = tmp[t];
}

void merge_sort(Element a[], int l, int r, Element tmp[])
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
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        Element elements[100];
        int count = 0;

        while (ss >> elements[count].str)
        {
            elements[count].len = elements[count].str.size();
            elements[count].idx = count;
            count++;
        }

        Element tmp[100];
        merge_sort(elements, 0, count, tmp);

        for (int j = 0; j < count; j++)
            cout << elements[j].str << " ";
        cout << "\n";
    }

    return 0;
}
