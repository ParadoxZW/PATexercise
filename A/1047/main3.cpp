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

vector<int> cour[3000];
int n, m, c;
int k;
char name[40010][5];

bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
}

int main(void) {
    scanf("%d %d", &n, &m);
    // cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &c);
        // cin >> name[i] >> c;
        for (int j = 0; j < c; j++) {
            scanf("%d", &k);
            cour[k].push_back(i);
        }
    }
    for (int i = 1; i < m + 1; i++) {
        printf("%d %d\n", i, cour[i].size());
        // cout << i << ' ' << cour[i].size() << endl;
        sort(cour[i].begin(), cour[i].end(), cmp);
        for (auto j : cour[i]) {
            printf("%s\n", name[j]);
            // cout << name[j] << endl;
        }
    }
    return 0;
}