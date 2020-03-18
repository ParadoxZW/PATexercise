#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int isDigit(int a){
    if (a >= '0' && a <= '9'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int a, b, c, cnt = 0;
    char digit[100], vdigit[100];
    cin >> a >> b;
    //cout << a + b << endl;
    //printf("%d\n", a + b);
    c = a + b;
    sprintf(digit, "%d", c);
    c = strlen(digit);
    int i = 0;
    while(c--){
        vdigit[i++] = digit[c];
        cnt++;
        if (cnt % 3 == 0 && c > 0 && isDigit(digit[c-1])){
            vdigit[i++] = ',';
        }
    }
    while(i--){
        cout << vdigit[i];
    }
    cout << endl;
    return 0;
}
