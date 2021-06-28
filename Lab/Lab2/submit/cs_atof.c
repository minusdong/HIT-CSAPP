#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

// f means float, str means string
// When dec_temp == 1, the string reaches the decimal part. 
float cs_atof(char *str) {
    float f = 0, dec = 1;
    int dec_temp = 0;
    while((*str) != '\0') {
        if((*str) == '.')
            dec_temp = 1;
        else if (dec_temp) {
            dec *= 0.1;
            f = f + ((*str) - '0') * dec;
        }
        else
            f = f * 10 + (*str) - '0';
        str++;
    }
    return f;
}

int main()
{
    char a[MAX_LENGTH];
    printf("Input decimal: ");
    scanf("%s", a);
    printf("Converted number: %f\n", cs_atof(a));
    return 0;
}