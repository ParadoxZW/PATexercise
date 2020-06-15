#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// #include <mat_print>
using namespace std;

vector<string> cour[3000];
int n, m, c;
int k;
string name;

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name >> c;
        for (int j = 0; j < c; j++) {
            cin >> k;
            cour[k].push_back(name);
        }
    }
    for (int i = 1; i < m + 1; i++) {
        cout << i << ' ' << cour[i].size() << endl;
        sort(cour[i].begin(), cour[i].end());
        for (auto j:cour[i]) {
            cout << j << endl;
        }
    }
    return 0;
}