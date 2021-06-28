#include <stdio.h>

int main(void) {
    int x_int = 0x0;
    int y_int = 0x80000000;
    int z_int = 0x00000001;
    int u_int = 0x7f7fffff;
    int v_int = 0x00800000;
    int w_int = 0x7f800000;
    int h_int = 0x7fffffff;
    float x = *(float*)&x_int; // +0
    float y = *(float*)&y_int; // -0
    float z = *(float*)&z_int; // min_positive_float
    float u = *(float*)&u_int; // max_positive_float
    float v = *(float*)&v_int; // min_positive_normalized_float
    float w = *(float*)&w_int; // Positive_Infinity
    float h = *(float*)&h_int; // Nan
	printf("+0\n \tDecimal:%f\n", x);
	printf("-0\n \tDecimal:%f\n", y);
	printf("min_positive_float\n \tDecimal:%.50f\n", z);
	printf("max_positive_float\n \tDecimal:%f\n", u);
	printf("min_positive_normalized_float\n \tDecimal:%.50f\n", v);
	printf("Positive_Infinity\n \tDecimal:%f\n", w);
	printf("Nan\n \tDecimal:%f\n", h);
    return 0;
}