#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

// i means int, str means string
int cs_atoi(char *str)
{
    int i = 0;
    while ((*str) >= '0' && (*str) <= '9') {
        i = i * 10 + (*str) - '0';
        str++;
    }
    return i;
}

int main()
{
    char a[MAX_LENGTH];
    printf("Input integer: ");
    scanf("%s", a);
    printf("Converted number: %d\n", cs_atoi(a));
    return 0;
}