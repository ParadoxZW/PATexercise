#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// LL x;
int T, i;
// const LL maxn = 9223372036854775807LL;
#define maxs "9223372036854775807"
#define maxd "99999999999999999999"
char s[100];

int main(void)
{
    // printf("%lld\n", maxn);
    scanf("%d", &T);
    while(T--){
        bool flag = true;
        scanf("%s", s);
        i = strlen(s);
        if(i >= 21){
            printf("Zhang San will never have girlfriend!\n");
        }else{
           if( strcmp(s, maxd) == 0 ){
               printf("100000000000000000000\n");
               continue;
           }
           // printf("xx %s\n", s);
           while(i--){
               if(s[i] == '9'){
                   s[i] = '0';
               }else{
                   s[i]++;
                   printf("%s\n", s);
                   flag = false;
                   break;
               }

           }
           if(flag)
              printf("1%s\n", s); 
        }
    }
    return 0;
}
