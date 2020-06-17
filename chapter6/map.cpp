/**
 * map<typename1. typename2> mp;
 * typename = basic_type|STL_container
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;

int main(void) {
    map<char, int> mp;
    mp['c'] = 20;
    mp['a'] = 10;
    mp['1'] = 100;
    // printf("%d\n", mp['c']);
    for(auto i:mp){
        cout << i.first << ": " << i.second << endl;
    }
    // find
    // erase
    // size
    // clear
    return 0;
}