#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// #include <mat_print.hpp>
using namespace std;

char s[110];
bool flag = true;      // 前一个是空格
bool flag2 = false;    // 前一个是元音字母

int main(void) {
    cin.getline(s, 110);
    for (auto i : s) {
        if (i == '\0' || i == '\n') {
            break;
        }
        if (flag2) {
            flag2 = false;
            continue;
        } else if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
                   i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
            flag2 = true;
        }
        if (flag) { // 需要打印大写
            if (i == ' ') {
                putchar(i);
                flag = true;
            } else if (i >= 'A' && i <= 'Z') {
                putchar(i);
                flag = false;
            } else {
                putchar(i + 'A' - 'a');
                flag = false;
            }
        } else { // 需要打印小写
            if (i == ' ') {
                putchar(i);
                flag = true;
            } else if (i >= 'A' && i <= 'Z') {
                putchar(i + 'a' - 'A');
            } else {
                putchar(i);
            }
        }
    }

    return 0;
}