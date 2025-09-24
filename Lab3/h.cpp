#include <iostream>
using namespace std;

const int MAXN = 200005;
long long arr[MAXN];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int lines;
        cin >> lines;
        arr[i] = lines + (i > 0 ? arr[i - 1] : 0);
    }

    for (int b = 0; b < M; b++)
    {
        long long line;
        cin >> line;

        int left = 0, right = N - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] < line)
                left = mid + 1;
            else
                right = mid;
        }
        cout << left + 1 << endl;
    }

    return 0;
}
