#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int z[100];
double az[100];
int isDigit(int a){
    if (a >= '0' && a <= '9'){
        return 1;
    }else{
        return 0;
    }
}

int getline(int *x, double *ax){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> x[i] >> ax[i];
    }
    return k;
}

int main(){
    int x[100], y[100], kx, ky, *p;
    double ax[100], ay[100], *ap;
    kx = getline(x, ax);
    ky = getline(y, ay);
    int cnt = 0, cnt2 = 0, ikx = 0, iky = 0;
    while(kx != ikx || ky != iky){
        if(ky == iky){
            //z[cnt] = x[ikx];
            //az[cnt] = ax[ikx];
            //cnt++;
            //ikx++;
            cnt2 = (kx - ikx);
            p = x + ikx;
            ap = ax + ikx;
            break;
        }else if(kx == ikx){
            //z[cnt] = y[iky];
            //az[cnt] = ay[iky];
            //cnt++;
            //iky++;
            cnt2 = (ky - iky);
            p = y + iky;
            ap = ay + iky;
            break;
        }else if(x[ikx] > y[iky]){
            z[cnt] = x[ikx];
            az[cnt] = ax[ikx];
            cnt++;
            ikx++;
        }else if(x[ikx] < y[iky]){
            z[cnt] = y[iky];
            az[cnt] = ay[iky];
            cnt++;
            iky++;
        }else if(ax[ikx] + ay[iky] >= 0.1){ // mark!!
            z[cnt] = y[iky];
            az[cnt] = ay[iky] + ax[ikx];
            cnt++;
            iky++;
            ikx++;
        }
    }
    cout << cnt + cnt2;
    int i = 0;
    //cout.precision(2);
    while(i < cnt){
        printf(" %d %.1lf", z[i], az[i]);
        i++;
    }
    i = 0;
    while(i < cnt2){
        printf(" %d %.1lf", p[i], ap[i]);
        i++;
    }
    return 0;
}
