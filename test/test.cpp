#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>
// #define print_mat(mat,H,W) for_each(mat, mat + H, [=](int *a){for_each(a, a + W, [=](int e) { cout << e << " "; });cout << endl;})
using namespace std;
namespace vw = ranges::views;

int main(void) {
    int a[10][10] = {{1, 2, 3,}, {2, 3, 1}, {0, 1, 0},};
    int b[10] = {1, 2, 3, 2,};
    // print_mat(a, 3, 3);

    // [=](auto mat,int H,int W){for_each(mat,mat+H,[=](auto a){for_each(a,a+W,[=](auto e){cout<<e<<" ";});cout<<endl;});}(a,3,3);
    
    // auto s = b | vw::take(3) | ranges::to<vector>;
    // cout << vw::all(s) << endl;

    // auto s = b | vw::take(3);
    // cout << s<< endl;

    // vector<string> s = b | vw::take(3) |
    //                    vw::transform([=](auto e) { return "0"+to_string(e); }) |
    //                    ranges::to<vector<string>>;
    // cout << (string)(s | vw::join("") | ranges::to<string>) << endl;


    int H = 3, W = 3;
    [=](auto &mat,int H,int W){mat|vw::take(H)|vw::transform([=](auto &l){cout<<(l|vw::take(W))<< endl;return 0;})|ranges::to<vector>;}(a, 3, 3);

    // ;
    // | vw::all | vw::join("|");
    // cout << s << endl;
    // for(auto i:s){
    //     cout << i << endl;
    // }
    // string ss = ;
    return 0;
}