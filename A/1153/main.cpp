#include <bits/stdc++.h>
using namespace std;

struct Testee {
    string re;
    string date;
    int score;
};

const int maxn = 10010;
Testee tees[maxn];
int N, M;
int x;
char res[20];
int ss[1010];
vector<int> ts[1010];
set<int> site_no;

bool cmp(int a, int b) {
    if (tees[a].score != tees[b].score) {
        return tees[a].score > tees[b].score;
    } else  {
        return tees[a].re < tees[b].re;
    }
}
int ty, term;
char tc;
map<char, vector<int> > tl;

struct TP {
    int site, num;
};

bool cmp2(TP a, TP b) {
    if (a.num != b.num) {
        return a.num > b.num;
    } else {
        return a.site < b.site;
    }
}
int site_;
string s;
int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        scanf("%s %d", res, &x);
        tees[i].re = res;
        tl[res[0]].push_back(i);
        tees[i].score = x;
        site_ = (res[1]-'0') * 100 + (res[2]-'0') * 10 + (res[3] - '0');
        site_no.insert(site_);
        ss[site_] += x;
        ts[site_].push_back(i);
        x = atoi(res + 4);
        tees[i].date = tees[i].re.substr(4, 6);
    }
    
    sort(tl['B'].begin(), tl['B'].end(), cmp);
    sort(tl['A'].begin(), tl['A'].end(), cmp);
    sort(tl['T'].begin(), tl['T'].end(), cmp);
    for (int w = 1; w <= M; w++) {
        /*loop body*/
        // scanf("%d %s", &ty, );
        cin >> ty >> s;
        printf("Case %d: %d %s\n", w, ty, s.c_str());

        if (ty == 1){
            if(tl[s[0]].size() == 0) {
                printf("NA\n");
            } else {
                for (auto ii: tl[s[0]]) {
                    printf("%s %d\n", tees[ii].re.data(), tees[ii].score);
                }
            }
        } else if(ty == 2){
            term = atoi(s.c_str());
            auto p = site_no.find(term);
            if (p == site_no.end()) {
                printf("NA\n");
            } else {
                printf("%d %d\n", ts[term].size(), ss[term]);
            }
        } else {
            vector<TP> ans;
            for (int k : site_no) {
                TP tp;
                tp.site = k;
                tp.num = 0;
                for (int ii : ts[k]) {
                    if (tees[ii].date == s) {
                        tp.num++;
                    }
                }
                if (tp.num > 0) {
                    ans.push_back(tp);
                }
            }
            sort(ans.begin(), ans.end(), cmp2);
            if (ans.size() > 0) {
                for (auto j : ans) {
                    printf("%d %d\n", j.site, j.num);
                }
            } else {
                printf("NA\n");
            }
        }
            
    }

    return 0;
}