#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int nth_prime(int n)
{
    if (n < 1)
        return -1;
    int count = 0;
    int num = 1;
    while (count < n)
    {
        num++;
        if (isPrime(num))
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