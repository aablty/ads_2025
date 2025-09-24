#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int sizes[N];

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x2 > y2)
            sizes[i] = x2;
        else
            sizes[i] = y2;
    }

    sort(sizes, sizes + N);
    cout << sizes[K - 1] << endl;

    return 0;
}
