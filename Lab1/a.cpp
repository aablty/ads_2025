#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int deck[1000];
        int deck_size = 0;

        for (int card = n; card >= 1; card--)
        {

            for (int i = deck_size; i > 0; i--)
            {
                deck[i] = deck[i - 1];
            }
            deck[0] = card;
            deck_size++;

            for (int moves = 0; moves < card; moves++)
            {
                int back_card = deck[deck_size - 1];

                deck_size--;

                for (int i = deck_size; i > 0; i--)
                {
                    deck[i] = deck[i - 1];
                }
                deck[0] = back_card;
                deck_size++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << deck[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}