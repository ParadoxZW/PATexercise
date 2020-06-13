#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int now = 0, nxt = 0, t = 0;

int main(void) {
    scanf("%d", &nxt);
    while (~scanf("%d", &nxt)) {
        if (nxt > now){
            t += (nxt - now) * 6 + 5;
        }else if (nxt < now){
            t += (now - nxt) * 4 + 5;
        }else{
            t += 5;
        }
        cout << t << endl;
        now = nxt;
    }
    printf("%d", t);

    return 0;
}