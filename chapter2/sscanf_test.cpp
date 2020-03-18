#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100] = "I love you!\n";
    char str2[100];
    sscanf(str1, "%*[^ ] %[^ ]", str2); // love
    puts(str2);
    return 0;
}
