#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<string>
using namespace std;

map<string, vector<int> > list;
vector<string> cour[3000];
int n, m, c;
int k;
string name;

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name >> c;
        vector<int> v;
        list[name] = v;
        for (int j = 0; j < c; j++) {
            cin >> k;
            list[name].push_back(k);
        }
    }
    for (auto i:list) {
        for (auto j:i.second){
            cour[j].push_back(i.first);
        }
    }
    for (int i = 1; i < m + 1; i++) {
        cout << i << ' ' << cour[i].size() << endl;
        for (auto j:cour[i]) {
            cout << j << endl;
        }
    }
    return 0;
}