#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

double w, t, l, bst[3], ans = 1;

int main(void) {
    for (int i = 0; i < 3; i++) {
        cin >> w >> t >> l;
        if (w >= t && w >= l) {
            cout << "W ";
            bst[i] = w;
        } else if (t >= w && t >= l) {
            cout << "T ";
            bst[i] = t;
        } else {
            cout << "L ";
            bst[i] = l;
        }
    }
    for (int i = 0; i < 3; i++) {
        ans *= bst[i];
    }
    printf("%.2f\n", (ans * 0.65 - 1) * 2);
    return 0;
}