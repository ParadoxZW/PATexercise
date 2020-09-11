#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
    string id;
    int gra;
};

vector<node> ans;

bool cmp(node a, node b) {
    if (a.gra != b.gra) {
        return a.gra > b.gra;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<node> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i].id >> list[i].gra;
    }

    for (int i = 1; i <= m; i++) {
        ans.clear();
        int num;
        string s;
        cin >> num >> s;
        int cnt = 0, sum = 0;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        if (num == 1) {
            for (int j = 0; j < n; j++) {
                if (list[j].id[0] == s[0]) {
                    ans.push_back(list[j]);
                }
            }
        } else if (num == 2) {
            for (int j = 0; j < n; j++) {
                if (list[j].id.substr(1, 3) == s) {
                    cnt++;
                    sum = sum + list[j].gra;
                }
            }
            if (cnt != 0) {
                printf("%d %d\n", cnt, sum);
            }
        } else if (num == 3) {
            unordered_map<string, int> mp;
            for (int j = 0; j < n; j++) {
                if (list[j].id.substr(4, 6) == s) {
                    mp[list[j].id.substr(1, 3)]++;
                }
            }
            for (auto it = mp.begin(); it != mp.end(); it++) {
                ans.push_back(node{it->first, it->second});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        for (int j = 0; j < ans.size(); j++) {
            printf("%s %d\n", ans[j].id.c_str(), ans[j].gra);
        }
        if (((num == 1 || num == 3) && ans.size() == 0) ||
            num == 2 && cnt == 0) {
            printf("NA\n");
        }
    }

    return 0;
}
