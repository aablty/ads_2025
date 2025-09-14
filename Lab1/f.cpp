#include <iostream>
using namespace std;

int nth_prime(int n)
{
    if (n < 1)
        return -1;
    int count = 0;
    int num = 1;
    while (count < n)
    {
        num++;
        bool is_prime = true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            count++;
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << nth_prime(n);

    return 0;
}