#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <mat_print.hpp>
// #include <range/v3/all.hpp>
// #include <string>
// #include <vector>
using namespace std;
// namespace vw = ranges::views;

// #define mp(mat,H,W) for_each(mat,mat+H, [=](int *a){for_each(a,a+W, [=](int e){cout << e << " ";});cout<<endl;})

// auto powerful_mp = /* generic */ \
[=](auto mat,int H,int W){for_each(mat,mat+H,[=](auto a){for_each(a,a+W,[=](auto e){cout<<e<<" ";});cout<<endl;});};

// auto more_powerful_mp = /* generic, functional, and beautiful */ \
[=](auto &mat,int H,int W){mat|vw::take(H)|vw::transform([=](auto &l){cout<<(l|vw::take(W))<<endl;return 0;})|ranges::to<vector>;};

int main(void) {
    int a[10][10] = {{1, 2, 3, 2}, {2, 3, 1, 1}, {0, 1, 0, 1},};
    mp(a, 3, 4);
    // cout << endl;
    // powerful_mp(a, 3, 4);
    // cout << endl;
    // more_powerful_mp(a, 3, 4);
    return 0;
}