#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 30
// str means string
char str[MAX_LENGTH];

// f_palce means 10^(Place Value of integer part)
// f means float, m means mark of str
void cs_ftoa(float f)
{
    int m = 0, temp_int;
    float f_palce = 10;
    while (f_palce < f) // integer part
        f_palce *= 10;
    while (f >= 1) {
        f_palce /= 10;
        temp_int = (int)(f / f_palce);
        str[m++] = temp_int + '0';
        f -= temp_int * f_palce;
    }
    str[m++] = '.'; // decimal point
    for (int i = 0; i < 6; i++) { // keep six decimal places
        f *= 10;
        str[m++] = (int)f + '0';
        f -= (int)f;
    }
    str[m++] = '\0';
    return;
}

int main()
{
    float f;
    printf("Input float: ");
    scanf("%f", &f);
    cs_ftoa(f);
    printf("Converted string: %s\n", str);
    return 0;
}