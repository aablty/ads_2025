#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            cout << "Yes";
            return 0;
        }
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "No";
    return 0;
}
