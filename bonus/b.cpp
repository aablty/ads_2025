#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    vector<bool> is_prime(b + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= b; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    bool first = true;
    for (int i = a; i <= b; i++) {
        if (is_prime[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;
    
    return 0;
}