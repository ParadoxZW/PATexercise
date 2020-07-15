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

typedef set<int> ids;
map<string, ids> tit2id;
map<string, ids> aut2id;
map<string, ids> kw2id;
map<string, ids> pub2id;
map<int, ids> py2id;

int N, M;
int bid, bpy;
string title, author, pub;
char kws[1110];

template <class T> 
void addItem(map<T, ids> &dict, T s, int bid) {
    auto it = dict.find(s);
    if (it == dict.end()) {
        ids v;
        v.insert(bid);
        dict[s] = v;
    } else {
        dict[s].insert(bid);
    }
}

template <class T> 
void find(map<T, ids> &dict, T s) {
    auto it = dict.find(s);
    if (it == dict.end()) {
        cout << "Not Found" << endl;
    } else {
        ids &vec = it->second;
        for (int i : vec) {
            printf("%07d\n", i); // !!!
        }
    }
}

void search(int c, string s) {
    if (c == 1) {
        find(tit2id, s);
    } else if (c == 2) {
        find(aut2id, s);
    } else if (c == 3) {
        find(kw2id, s);
    } else if (c == 4) {
        find(pub2id, s);
    } else {
        int yy = atoi(s.c_str());
        find(py2id, yy);
    }
}

int main(void) {
    #ifdef LOCAL
        freopen("./1022/1.txt", "r", stdin);
    #endif
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        cin >> bid;
        cin.ignore();
        // getline(cin, number);
        // bid = atoi(number.c_str());
        getline(cin, title);
        getline(cin, author);
        cin.getline(kws, 1100);
        getline(cin, pub);
        cin >> bpy;
        cin.ignore();
        addItem(tit2id, title, bid);
        addItem(aut2id, author, bid);
        addItem(pub2id, pub, bid);
        addItem(py2id, bpy, bid);
        int k, j = k = 0;
        for (; j <= strlen(kws); j++) {
            if (kws[j] == ' ' || kws[j] == '\0') {
                string s = string(kws + k, kws + j);
                addItem(kw2id, s, bid);
                k = j + 1;
            }
        }
    }
    cin >> M;
    cin.ignore();
    string line;
    int c;
    for (int i = 0; i < M; i++) {
        scanf("%d: ", &c);
        getline(cin, line);
        cout << c << ": " << line << endl;
        search(c, line);
    }
    return 0;
}