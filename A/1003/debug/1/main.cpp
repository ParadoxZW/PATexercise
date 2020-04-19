#include <iostream>
#include <cstdio>
#include <cstring>

#include <string>

using namespace std;

int main()

{

    int n, len;

    cin >> n;

    for (int i = 1; i <= n; i++)

    {

        cin >> len;

        char a[2005] = {};
        getchar();

        cin.getline(a, 2005);

        int len1 = strlen(a);

        while (len1 < len)

        {

            strcat(a, "zsbd");
            len1 += 4;
        }

        cout << a << endl;
    }
}
