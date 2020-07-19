#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 100001;
const int bs = 136;
const int bn = 137;

int table[maxn];
int block[maxn];
stack<int> stk;
int N;
char cmd[40];
int v;

void pop() {
    if (stk.size() == 0) {
        cout << "Invalid" << endl;
        return;
    }
    int v = stk.top();
    stk.pop();
    cout << v << endl;
    table[v]--;
    block[v/bs]--;
}

void push(int v) {
    stk.push(v);
    table[v]++;
    block[v/bs]++;
}

void peekMedian() {
    if (stk.size() == 0) {
        cout << "Invalid" << endl;
        return;
    }
    int num = 0, i, j;
    int mid = (stk.size() + 1) / 2;
    for (i = 0; num + block[i] < mid; i++) {
        num += block[i];
    }
    // while(true) {
    //     if (num + block[i] < mid) {
    //         num += block[i];
    //     } else {
    //         break;
    //     }
    //     i++;
    // }
    for (j = bs * i; num + table[j] < mid; j++) {
        num += table[j];
    }
    cout << j << endl;
    // int j = bs * i;
    // while(true) {
    //     if (num + table[j] < mid) {
    //         num += table[j];
    //     } else {
    //         cout << j << endl;
    //         break;
    //     }
    //     j++;
    // }
}

int main(void) {
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        cin.getline(cmd, 35);
        if(cmd[1] == 'o') { // Pop
            pop();
        } else if (cmd[1] == 'e') { // PeekMedian
            peekMedian();
        } else { // Push
            sscanf(cmd + 5, "%d", &v);
            push(v);
        }
    }

    return 0;
}