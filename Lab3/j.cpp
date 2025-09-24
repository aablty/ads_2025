#include <iostream>
using namespace std;

bool canSteal(const int *bags, int N, int H, int limit)
{
    int flights = 0;
    for (int i = 0; i < N; ++i)
    {
        flights += (bags[i] + limit - 1) / limit;
    }
    return flights <= H;
}

int main()
{
    int N, H;
    cin >> N >> H;
    int bags[10000];
    for (int i = 0; i < N; i++)
        cin >> bags[i];

    int max_c = bags[0];
    for (int i = 1; i < N; ++i)
        if (bags[i] > max_c)
            max_c = bags[i];

    int left = 1, right = max_c;
    int answer = right;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canSteal(bags, N, H, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
