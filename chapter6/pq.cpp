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

int main(void) {
    priority_queue<int> pq;
    cout << pq.empty() << endl;
    cout << endl;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.empty() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << endl;
    cout << pq.empty() << endl;

    return 0;
}