#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[100000];
    int prefix[100000];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int min_len = n + 1;
    for (int left = 0; left < n; left++) {
        int low = left + 1, high = n, ans = n + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = prefix[mid] - prefix[left];
            if (sum >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans <= n) {
            min_len = min_len < (ans - left) ? min_len : (ans - left);
        }
    }
    cout << min_len << endl;
    return 0;
}
