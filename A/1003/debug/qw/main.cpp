#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t,n,a1,a2,start;
    double num;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    { 
        n=0;
    scanf("%d",&n);
    scanf("%d",&start);
    // if (n==1){
    //    num =1.0/start;
    //    printf("%0.2f\n",num);
    //    continue;
    // }
    // if (n==2){
    //     scanf("%d", &a1);
    //    num =1.0/(start>a1?start:a1);
    //    printf("%0.2f\n",num * 2);
    //    continue;
    // }
    a1 = start;
       for (int j = 0; j < n-1; j++)
       {
           if(j != 0)
            a1 = a2;
           scanf("%d",&a2);
           num+=1.0/(a1>a2?a1:a2);
       }
    num+=1.0/(start>a2?start:a2);
       printf("%0.2f\n",num);

}
}

