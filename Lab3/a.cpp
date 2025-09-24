#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int target)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    int *to_find = new int[T];
    for (int i = 0; i < T; ++i)
        cin >> to_find[i];

    int N, M;
    cin >> N >> M;
    int size = N * M;

    int *arr = new int[size];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int x;
            cin >> x;
            int snakeIndex;
            if (i % 2 == 0)
                snakeIndex = i * M + j;
            else
                snakeIndex = i * M + (M - 1 - j);
            arr[size - 1 - snakeIndex] = x;
        }
    }

    for (int k = 0; k < T; ++k)
    {
        int idx = binary_search(arr, size, to_find[k]);
        if (idx == -1)
        {
            cout << -1 << '\n';
        }
        else
        {
            int orig = size - 1 - idx;
            int row = orig / M;
            int col = orig % M;

            if (row % 2 == 1)
                col = M - 1 - col;
            cout << row << " " << col << '\n';
        }
    }

    delete[] to_find;
    delete[] arr;
    return 0;
}
