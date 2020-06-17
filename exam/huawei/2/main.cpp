#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

char s[1010];
int m, k;
bool flag;

int main(void) {
    cin.getline(s, 1010);
    cin >> m;
    // k = m;
    int i = 0, j;
    int len = strlen(s);
    len--;
    // cout << len << endl;
    // cout << s << endl;
    while(i<len && s[i]!='\0' && s[i]!='\n' ){
        if (s[i] == ' '){
            i++;
            continue;
        }
        j = min(i + m, len);
        if(s[j-2] == ' '){
            j--;
            // flag = false;
        } else if ((s[j - 1] >= 'a' && s[j - 1] <= 'z') ||
                   (s[j - 1] >= 'A' && s[j - 1] <= 'Z')){
            if ((s[j] >= 'a' && s[j] <= 'z') ||
                (s[j] >= 'A' && s[j] <= 'Z')){
                // cout << s[j] << endl;
                j--;
                flag = true;
            }
        }
        // cout << i << ' '<< j << endl;
        putchar('{');
        for (int t = i; t < j; t++) { 
            // cout << s[t];
            putchar(s[t]); 
        }
        if(flag){
            putchar('-');
        }
        // cout << '}' << endl;
        putchar('}');
        putchar('\n');
        // cout << "==" << endl;
        i = j;
        flag = false;
    }

    return 0;
}