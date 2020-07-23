#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand());
    }
    return 0;
}