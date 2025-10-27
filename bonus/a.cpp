#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Passenger
{
    int id;
    long long benefit;
    int state;

    Passenger(int id, long long benefit) : id(id), benefit(benefit), state(0) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, P;
    cin >> N >> M >> P;

    vector<Passenger> passengers;
    passengers.reserve(N);
    vector<vector<Passenger *>> enters(P + 1);
    vector<vector<Passenger *>> exits(P + 1);

    long long total = 0;

    for (int i = 0; i < N; i++)
    {
        long long a, b;
        int start, end;
        cin >> a >> b >> start >> end;

        total += b * (end - start);

        if (a > b)
        {
            passengers.push_back(Passenger(i, a - b));
            enters[start].push_back(&passengers.back());
            exits[end].push_back(&passengers.back());
        }
    }

    auto lessComp = [](Passenger *left, Passenger *right)
    {
        return left->benefit < right->benefit;
    };

    auto greaterComp = [](Passenger *left, Passenger *right)
    {
        return left->benefit > right->benefit;
    };

    priority_queue<Passenger *, vector<Passenger *>, decltype(lessComp)> standing(lessComp);
    priority_queue<Passenger *, vector<Passenger *>, decltype(greaterComp)> sitting(greaterComp);

    long long sittingSum = 0;
    int sittingCount = 0;

    for (int stop = 1; stop < P; stop++)
    {
        for (Passenger *p : exits[stop])
        {
            if (p->state == 2)
            {
                p->state = 0;
                sittingSum -= p->benefit;
                sittingCount--;
            }
            else
            {
                p->state = 0;
            }
        }

        for (Passenger *p : enters[stop])
        {
            p->state = 1;
            standing.push(p);
        }

        while (sittingCount < M && !standing.empty())
        {
            Passenger *p = standing.top();
            standing.pop();

            if (p->state == 0)
                continue;

            p->state = 2;
            sitting.push(p);
            sittingCount++;
            sittingSum += p->benefit;
        }

        while (!sitting.empty() && !standing.empty() && sitting.top()->benefit < standing.top()->benefit)
        {
            Passenger *sit = sitting.top();
            Passenger *stand = standing.top();

            if (sit->state == 0)
            {
                sitting.pop();
                continue;
            }
            if (stand->state == 0)
            {
                standing.pop();
                continue;
            }

            sitting.pop();
            standing.pop();

            sittingSum -= sit->benefit;
            sittingSum += stand->benefit;

            sit->state = 1;
            stand->state = 2;

            standing.push(sit);
            sitting.push(stand);
        }

        total += sittingSum;
    }

    cout << total << endl;

    return 0;
}
