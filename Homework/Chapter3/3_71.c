/*
 3.71?
 */

#include <stdio.h>
#define MAX_SIZE 10
void good_echo( )
{
    char str[MAX_SIZE];
    while(1) {
        char *p = fgets(str, MAX_SIZE, stdin);
        if (p == NULL) break;
        printf("%s", p);
    }
}