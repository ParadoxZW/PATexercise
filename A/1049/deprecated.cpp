#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <mat_print.hpp>
using namespace std;

typedef  unsigned int ui;
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
ui basis[12] = {0, 1, 19, 271, 3439, 40951, 468559, 5217031, 56953279,
         612579511, 2218248303
};
ui n, l, h, tmp;

int calc(int n) {
    // scanf("%d\n", &n);
    ui s, h, tmp = n, l = 0;
    while(tmp > 0){
        h = tmp;
        tmp /= 10;
        l++; 
    }
    tmp = basis[l-1];
    cout << l << ' ' << h << ' ' << tmp << ' ' << tp[l] << endl;
    if (h > 1){
        s = (h - 1) * tmp + tp[l];
        s += calc(n - h*tp[l]);
    }else{
        s = tmp + n - tp[l] + 1;
    }
    return s;
}

int main(void) {
    for (int i = 1; i < 12; i++) {
        basis[i] = 10 * basis[i-1] + tp[i];
        cout << basis[i] << ' ';
    }

    return 0;
}