#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int N, M, K;
int node[maxn];
vector<pair<int, int>> edges;
int x, y;

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        edges.push_back(make_pair(x, y));
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        set<int> colors;
        for (int j = 0; j < N; j++) {
            scanf("%d", &x);
            colors.insert(x);
            node[j] = x;
        }
        y = colors.size();
        for (auto p:edges) {
            if (node[p.first] == node[p.second]) {
                y = -1;
            }
        }
        if (y == -1) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << y << "-coloring" << std::endl;
        }
    }

    return 0;
}