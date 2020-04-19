#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t, n,m;
    cin >> t;
    for (int i = 1; i <= t; i++)

    { 

        int n,m,k;

        cin>>n>>m;

        int a[100001];

        int num; 

        cin>>a[0];
    
        num = 1;
        int flag = 1;
        while (flag < n) 
        {
            cin>>a[flag];
            for (int j = 0; j < flag; j++)
            {
                num = (num%m *(int)(abs(a[j] - a[flag]))%m)%m;
            }
            flag++;
        }
        cout<<num<<endl;

    }

}

