#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int *uniques = new int[N];
    int *freq = new int[N];
    int uniqueCount = 0;
    int maxFreq = 0;

    for (int i = 0; i < N; i++)
    {
        bool found = false;
        int pos = -1;

        for (int j = 0; j < uniqueCount; j++)
        {
            if (arr[i] == uniques[j])
            {
                found = true;
                pos = j;
                break;
            }
        }

        if (found)
        {
            freq[pos]++;
        }
        else
        {
            uniques[uniqueCount] = arr[i];
            freq[uniqueCount] = 1;
            uniqueCount++;
        }

        if (found && freq[pos] > maxFreq)
            maxFreq = freq[pos];
        else if (!found && maxFreq == 0)
            maxFreq = 1;
    }

    int *ans = new int[uniqueCount];
    int ansCount = 0;

    for (int i = 0; i < uniqueCount; i++)
    {
        if (freq[i] == maxFreq)
        {

            int j = ansCount;
            while (j > 0 && ans[j - 1] < uniques[i])
            {
                ans[j] = ans[j - 1];
                j--;
            }
            ans[j] = uniques[i];
            ansCount++;
        }
    }

    for (int i = 0; i < ansCount; i++)
        cout << ans[i] << " ";

    delete[] arr;
    delete[] uniques;
    delete[] freq;
    delete[] ans;

    return 0;
}