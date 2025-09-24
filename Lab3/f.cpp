#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int competitors[N];
    for (int i = 0; i < N; i++)
        cin >> competitors[i];

    int P;
    cin >> P;

    int power[P];
    for (int i = 0; i < P; i++)
        cin >> power[i];

    for (int i = 0; i < P; i++)
    {
        int count = 0;
        int t_power = 0;
        for (int j = 0; j < N; j++)
        {
            if (competitors[j] <= power[i])
            {
                count++;
                t_power += competitors[j];
            }
        }
        cout << count << " " << t_power << endl;
    }

    return 0;
}
