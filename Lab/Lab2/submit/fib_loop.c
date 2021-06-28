#include <stdio.h>

int fib_loop_int() {
    int i, temp_1 = 0, temp_2 = 1, max_fib = 1;
    for (i = 1; max_fib >= 0; i++) {
        max_fib = temp_1 + temp_2;
        temp_1 = temp_2;
        temp_2 = max_fib;
    }
    return i;
}

int fib_loop_long() {
    int i;
	long temp_1 = 0, temp_2 = 1, max_fib = 1;
	for (i = 1; max_fib >= 0; i++){
		max_fib = temp_1 + temp_2;
		temp_1 = temp_2;
		temp_2 = max_fib;
	}
	return i;
}

int fib_loop_unsigned_int() {
    int i;
    unsigned int temp_1 = 0, temp_2 = 1, max_fib = 1;
    for (i = 1; temp_1 <= temp_2; i++) {
        max_fib = temp_1 + temp_2;
        temp_1 = temp_2;
        temp_2 = max_fib;
    }
    return i;
}

int fib_loop_unsigned_long() {
    int i;
    unsigned long temp_1 = 0, temp_2 = 1, max_fib = 1;
    for (i = 1; temp_1 <= temp_2; i++) {
        max_fib = temp_1 + temp_2;
        temp_1 = temp_2;
        temp_2 = max_fib;
    }
    return i;
}

int main(void)
{
    printf("For int, when n = %d, data overflow.\n", fib_loop_int());
    printf("For long, when n = %d, data overflow.\n", fib_loop_long());
    printf("For unsigned int, when n = %d, data overflow.\n", fib_loop_unsigned_int());
    printf("For unsigned long, when n = %d, data overflow.\n", fib_loop_unsigned_long());
	return 0;
}
