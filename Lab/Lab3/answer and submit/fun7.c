#include <stdio.h>

int *rdi;

int fun7(int *rdi, int esi) {
    int eax = *rdi;
    if (eax > esi) {
        *rdi += 8;
        eax = 2 * fun7(rdi, esi);
    }
    else if (eax < esi) {
        *rdi += 16;
        eax = 2 * fun7(rdi, esi) + 1;
    }
    else return 0;
}

int main() {
    *rdi = 36;
    printf("%d", fun7(rdi, 0));
    return 0;
}