#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Hello, World!\n");
    char str[100];
    fgets(str, 100, stdin);
    printf("%s", str);
    return 0;
}
