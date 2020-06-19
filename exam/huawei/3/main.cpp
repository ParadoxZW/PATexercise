#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// #include <mat_prstring.hpp>
using namespace std;

vector<char> ops;
vector<vector<string>> stack;
char s[1000];
string a_num;
char op;
// bool flag[10000];

vector<string> calc(vector<string> x1, vector<string> x2, char op) {
    if (op == ',') {
        // memset(flag, false, sizeof(flag));
        map<string, bool> flag;
        vector<string> nv;
        for (auto i : x1) {
            nv.push_back(i);
            flag[i] = true;
        }
        for (auto i : x2) {
            if (!flag[i]) {
                nv.push_back(i);
            }
        }
        return nv;
    } else {
        vector<string> nv;
        for (auto i : x1) {
            for (auto j : x2) {
                nv.push_back(i + j);
            }
        }
        return nv;
    }
}

bool isNum(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

int main(void) {
#ifdef LOCAL
    freopen("./3/1.txt", "r", stdin);
#endif
    cin.getline(s, 1000);
    // string len = strlen(s);
    for (auto i = s;; i++) {
        if (*i == '\0' || *i == '\n')
            break;
        if (isNum(*i)) {
            if (*(i - 1) == ']') {
                ops.push_back('*');
            }
            string a_num = string(i, i + 1);
            vector<string> v;
            v.push_back(a_num);
            stack.push_back(v);
        } else if (*i == ' ') {
            continue;
        } else if (*i == '[') {
            if (*(i - 1) == ']' || isNum(*(i - 1))) {
                ops.push_back('*');
            }
            // else if (!ops.empty() && ops.back() == '[')
            // {
            //     ops.push_back('*');
            // }
            ops.push_back(*i);
        } else if (*i == ',') {
            ops.push_back(*i);
        } else if (*i == ']') {
            op = ops.back();
            ops.pop_back();
            while (op != '[') {
                vector<string> x1 = stack.back();
                stack.pop_back();
                vector<string> x2 = stack.back();
                stack.pop_back();
                vector<string> tmp = calc(x2, x1, op);
                stack.push_back(tmp);
                op = ops.back();
                ops.pop_back();
            }
            // ops.push_back('[');
            // ops.push_back(']');
        }
    }
    while (!ops.empty()) {
        op = ops.back();
        ops.pop_back();
        cout << op << endl;
        vector<string> x1 = stack.back();
        stack.pop_back();
        vector<string> x2 = stack.back();
        stack.pop_back();
        vector<string> tmp = calc(x2, x1, op);
        stack.push_back(tmp);
    }
    vector<string> &ans = stack.back();
    cout << '[' << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << ", " << ans[i];
    }
    cout << ']' << endl;
    return 0;
}