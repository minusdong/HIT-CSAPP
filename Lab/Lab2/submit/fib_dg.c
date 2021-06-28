#include <stdio.h>

int fib_dg_int(int i) {
    if (i = 0)
        return 0;
    else if (i == 1 || i == 2)
        return 1;
    else return fib_dg_int(i-1) + fib_dg_int(i-2);
}

unsigned int fib_dg_unsigned_int(int i) {
    if (i = 0)
        return 0;
    else if (i == 1 || i == 2)
        return 1;
    else return fib_dg_int(i-1) + fib_dg_int(i-2);
}

long fib_dg_long(int i) {
    if (i = 0)
        return 0;
    else if (i == 1 || i == 2)
        return 1;
    else return fib_dg_int(i-1) + fib_dg_int(i-2);
}

unsigned long fib_dg_unsigned_long(int i) {
    if (i = 0)
        return 0;
    else if (i == 1 || i == 2)
        return 1;
    else return fib_dg_int(i-1) + fib_dg_int(i-2);
}

int main(void) {
    int i;
    int int_count;
    unsigned int uint_count, last_uint_count = 0;
    long long_count;
    unsigned long ulong_count, last_ulong_count = 0;

    int_count = fib_dg_int(1);
    for (i = 1; int_count >= 0; i++) {
        printf("int_Fib(%d) = %d.\n", i, int_count);
        int_count = fib_dg_int(i+1);
    }
    printf("For int, when n = %d, data overflow.\n", i);
    
    uint_count = fib_dg_unsigned_int(1);
    for (i = 1; uint_count >= last_uint_count; i++) {
        printf("unsigned_int_Fib(%d) = %u.\n", i, uint_count);
        last_uint_count = uint_count;
        uint_count = fib_dg_int(i+1);
    }
    printf("For unsigned int, when n = %d, data overflow.\n", i);
    
    long_count = fib_dg_long(1);
    for (i = 1; long_count >= 0; i++) {
        printf("long_Fib(%d) = %ld.\n", i, long_count);
        long_count = fib_dg_long(i+1);
    }
    printf("For long, when n = %d, data overflow.\n", i);

    ulong_count = fib_dg_unsigned_long(1);
    for (i = 1; ulong_count >= last_ulong_count; i++) {
        printf("unsigned_long_Fib(%d) = %lu.\n", i, ulong_count);
        last_ulong_count = ulong_count;
        ulong_count = fib_dg_int(i+1);
    }
    printf("For unsigned long, when n = %d, data overflow.\n", i);

    return 0;
}