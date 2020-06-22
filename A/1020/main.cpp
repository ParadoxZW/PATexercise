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

const unsigned int maxn = 1<<31;

struct node {
    int f, l, r, k;
};

node tree[maxn];
int post[32];
int inor[32];
int N;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inor[i];
    }
    

    return 0;
}