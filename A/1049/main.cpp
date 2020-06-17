#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

typedef unsigned int ui;
const ui tp[12] = {0,
                    1,
                    10,
                    100,
                    1000,
                    10000,
                    100000,
                    1000000,
                    10000000,
                    100000000,
                    1000000000};
ui basis[12] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000,};

int calc(int n) {
    // scanf("%d\n", &n);
    ui s, h, tmp = n, l = 0, r;
    if (n == 0) {
        return 0;
    }
    while (tmp > 0) {
        h = tmp;
        tmp /= 10;
        l++;
    }
    tmp = basis[l - 1];
    // cout << l << ' ' << h << ' ' << tmp << ' ' << tp[l] << endl;
    if (h > 1) {
        s = h * tmp + tp[l];
        s += calc(n - h * tp[l]);
    } else {
        r = n - tp[l];
        s = tmp + r + 1 + calc(r);
    }
    return s;
}

int main(void) {
    int n;
    cin >> n;
    cout << calc(n) << endl;

    return 0;
}
