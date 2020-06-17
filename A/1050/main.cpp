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

const int maxn = 10010;
char a[maxn], b[maxn];
bool exs[256];

int main(void) {

    cin.getline(a, maxn);
    cin.getline(b, maxn);
    // cout << a << b << endl;
    for (auto i:b) {
        exs[i] = true;
    }
    for (auto i:a) {
        if(!exs[i]){
            putchar(i);
        }
    }
    putchar('\n');
    return 0;
}