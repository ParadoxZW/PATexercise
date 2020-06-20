#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 1010;

int m, n, k;
int nums[maxn];
// vector<int> v;

int main(void) {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        stack<int> st;
        // st.push(1);
        int nxt = 1;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", nums + i);
        }
        // cout << (nums|vw::take(n)) << endl;
        // cout << st.top() << endl;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(nxt++);
            }
            while (st.top() != nums[i] && nums[i] >= nxt && st.size() <= m) {
                // cout << nxt << endl;
                st.push(nxt++);
                // cout << st.size() << endl;
            }
            if (st.size() > m) {
                flag = false;
                break;
            }
            if (st.top() == nums[i]) {
                // cout << st.top() << endl;
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}