#include <stdio.h>

int main(void) {
    float x = 1;
    printf("%f\n", x/0);
    printf("%f\n", x/1e-500);
    return 0;
}