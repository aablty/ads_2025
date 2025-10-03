#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1 << 15];
long long result[1 << 15];
int idx = 0;

void build(int l, int r)
{
    if (l > r)
        return;
    int m = (l + r) / 2;
    result[idx++] = arr[m];
    build(l, m - 1);
    build(m + 1, r);
}

int main()
{
    int N;
    cin >> N;
    int sz = (1 << N) - 1;

    for (int i = 0; i < sz; i++)
        cin >> arr[i];

    sort(arr, arr + sz);

    build(0, sz - 1);

    for (int i = 0; i < sz; i++)
        cout << result[i] << " ";

    return 0;
}
