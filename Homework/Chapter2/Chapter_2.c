//Chapter 2: 2.59, 2.63, 2.67, 2.71, 2.75, 2.79, 2.83, 2.87 , 2.91, 2.95, 2.96

#include <stdio.h>

/*
2.59题：
(0x89ABCDEF & 0xFF) | (0x76543210 & 0xFFFFFF00)
*/


/*
2.63题：
*/
unsigned srl(unsigned x, int k) {
    /* Perform shift logically */
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) * 8;
    unsigned z = 2 << (w - k - 1) - 1;
    return xsra & z;
}
int sra(int x, int k) {
    /* Perform shift arithmetically */
    int xsra = (unsigned) x >> k;
    int w = sizeof(int) * 8;
    int z = 1 << (w - k - 1);
    int right = xsra & (z - 1); 
    int left = z + (~(z - 1) & ~(xsra & z));
    return left | right;
}


/*
2.67题：
A. 如警告所说，问题在于“1 << 32”，左移范围在1~31
   左移位数等于int_32型宽度，在C语言中实际上移动位数是对宽度求余，即此处相当于没有移位。
B. 在int至少为32位的机器上正常运行
C. 在int至少为16位的机器上正常运行
*/
int int_size_is_32 (){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return (set_msb && !beyond_msb);
}
int int_size_is_32_in_16 (){
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}


/*
2.71题：
A. 代码错在整数移位最后都是逻辑右移，移位结果与实际结果可能不符，处理不了负数情况
B. 只使用左右移位和一个减法，代码如下：
*/
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum) {
    int z = (int)word << ((3 - bytenum) << 3);
    int w = (sizeof(int) - 1) << 3;
    return z >> w;
}


/*
2.75题：
*/
int signed_high_prod(int x, int y) {
    long long s = (long long) x * y;
    return s >> 32;
}
unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int s_x = x >> 31;
  int s_y = y >> 31;
  int m = signed_high_prod(x, y);
  return m + x * s_y + y * s_x;
}


/*
2.79题：
*/
int mul3div4 (int x) {
    int m =  (x >> 2) + (x >> 1);
    int low = ((x & 0x3) == 0x3);
    return m + low;
}


/*
2.83题：
A.  将0.yyyyy……的小数点右移k位得到y.yyyyy……
    假设0.yyyyy…… = x, Y+x=x*2^k
    x=Y/(2^k-1)
B.  (1) y=101     Y=5   k=3  x=5/7
    (2) y=0110    Y=6   k=4  x=6/15=2/5
    (3) y=010011  Y=19  k=6  x=19/63
*/


/*
2.87题：
    描述                Hex         M           E           V               D
-0                     8000         0          -14         -0             -0.0
最小的>2的值            4001      1025/1024      1       1025*2(-9)     2.001953125
512                    6000         1           9           512           512.0
最大的非规格化数        03FF       1023/1024     -14     1023*2(-24)   0.000060975516
-∞                     FC00        ---         ---          -∞              -∞
十六进制表示为3BB0的数   3BB0       123/64       -1       123*2^(-7)      0.9609375
*/


/*
2.91题：
    A. 11.0010010000111111011011
    B. 22/7=3+1/7=11+1/(2^3-1)
           =11.001001001……
    C. 对于二进制小数点后的每一位，我们从头对每个小数 *2，整数最低位是否相等，即二进制小数向右移动一位
       由此223/71*2^8的整数部分是804，小数部分的十进制为4/71
       同样22/7*2^8的整数部分是804，小数部分的十进制为4/7
       那么对小数部分再次 *2，得到的整数部分前一个为0，后一个为1
       所以从第9位开始不同
*/


/*
2.95题：
*/
typedef unsigned float_bits;
/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half (float_bits f) {
    float_bits s = f >> 31;             //sign
    float_bits exp = (f >> 23) & 0xFF;  //exponent
    float_bits frac = f & 0x7FFFFF;     //fraction
    if (exp == 0xFF)// frac==0 or frac!=0 return ∞ or NaN 
        return f;
    else {
        float_bits temp = (frac & 0x3 == 3);//Round to even
        if (exp == 0)
            frac = (frac >> 1) + temp;
        else if (exp == 1) {
            frac = ((frac + 0x800000) >> 1) + temp;//可能存在111111+1的情况
            exp -= 1;
            if (frac == 0x800000) {
                frac = 0;
                exp = 1;
            }
        }
        else exp -=1;
        return (s << 31) + (exp << 23) + (frac);
    }
}


//2.96题：
/*
 * Compute (int) f.
 * If conversion causes overflow or f is NaN, return 0x80000000.
 */
int float_f2i(float_bits f) {
    float_bits s = f >> 31;                     //sign
    float_bits exp = ((f >> 23) & 0xFF) - 127;  //exponent
    float_bits frac = f & 0x7FFFFF;             //fraction
    if (exp < 0) //int表示不了小数，纯小数向偶数0取整
        return 0;
    else if (exp >= 31) //Tmax = 2^31-1, Tmin = -2^31
        return 0x80000000; //边界问题欠考虑，主要是Tmin和
    if (exp >= 23)
        frac = frac << (exp - 23);
    else
        frac = frac >> (23 - exp);  //向偶数取整？？？欠考虑
    return s ? -(int)frac : (int)frac;
    // if (s) return -(int)frac;
    // else return (int)frac;
}
