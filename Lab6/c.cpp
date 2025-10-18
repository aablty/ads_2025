#include <iostream>
#include <climits>
using namespace std;

void merge_sort(long long* a, int l, int r, long long* tmp) {
    if (r - l <= 1) return;
    int m = l + (r - l) / 2;
    merge_sort(a, l, m, tmp);
    merge_sort(a, m, r, tmp);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i < m) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (int t = l; t < r; ++t) a[t] = tmp[t];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    long long* a = new long long[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n < 2) {
        delete[] a;
        return 0;
    }

    long long* tmp = new long long[n];
    merge_sort(a, 0, n, tmp);

    long long minDiff = LLONG_MAX;
    for (int i = 0; i + 1 < n; ++i) {
        long long d = a[i+1] - a[i];
        if (d < minDiff) minDiff = d;
    }

    bool first = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i+1] - a[i] == minDiff) {
            if (!first) cout << ' ';
            cout << a[i] << ' ' << a[i+1];
            first = false;
        }
    }
    cout << '\n';
    
    delete[] a;
    delete[] tmp;
    return 0;
}