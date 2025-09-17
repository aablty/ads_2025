#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        char *arr = new char[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];

            char nonRepeated = '#';

            for (int j = 0; j < i + 1; j++)
            {
                char current = arr[j];
                bool isRepeated = false;

                for (int k = 0; k < i + 1; k++)
                {
                    if (arr[k] == current && k != j)
                    {
                        isRepeated = true;
                        break;
                    }
                }

                if (!isRepeated)
                {
                    nonRepeated = current;
                    break;
                }
            }

            nonRepeated == '#' ? cout << -1 << " " : cout << nonRepeated << " ";
        }
        cout << endl;
        delete[] arr;
    }

    return 0;
}