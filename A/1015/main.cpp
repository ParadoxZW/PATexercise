#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N, D, m;

bool isPrime(int n) {
    int u = (int)sqrt(1.0 * n);
    for (int i = 2; i <= u; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int d_reverse(int n, int d) {
    int k = 0;
    while (n > 0) {
        k = k * d + n % d;
        n /= d;
    }
    return k;
}

int main(void) {
    cin >> N;
    while (N > 0) {
        cin >> D;
        if (N == 1 || !isPrime(N)) {
            cout << "No" << endl;
        } else {
            m = d_reverse(N, D);
            if (m == 1 || !isPrime(m)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
        cin >> N;
    }

    return 0;
}