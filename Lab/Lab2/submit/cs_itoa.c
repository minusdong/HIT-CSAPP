#include <stdio.h>
#include <stdlib.h>

// INT_MAX is 2147483647, 10 + '\0' = 11
#define MAX_LENGTH 11
// str means string
char str[MAX_LENGTH];

// int_place means 10^(Place Value)
// i means int, m means mark of str
void cs_itoa(int i)
{
    int m = 0, int_place = 10;
    while (int_place < i)
        int_place *= 10;
    while (i) {
        int_place /= 10;
        str[m++] = i / int_place + '0';
        i -= (i / int_place) * int_place;
    }
    str[m++] = '\0';
    return;
}

int main(void)
{
    int a;
    printf("Input integer: ");
    scanf("%d", &a);
    cs_itoa(a);
    printf("Converted string: %s\n", str);
    return 0;
}