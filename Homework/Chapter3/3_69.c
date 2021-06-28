/*
 3.69题
        void test(long i, b_struct *bp)
        i in %rdi, bp in %rsi
 1   <test>:
 2   mov    0x120(%rsi), %ecx
     # %ecx = %rsi + 0x120 (288)，访问 bp 的 first, %ecx 储存 n
 3   add    (%rsi), %rcx
     # %rcx = %rcx + %rsi，访问 bp 的 last
     # sizeof(int) + CNT * sizeof(a_struct) = 288
 4   lea    (%rdi, %rdi, 4), %rax
 5   lea    (%rsi, %rax, 8), %rax
     # %rax = bp + 40 * i, bp 是结构体的指针，指向 first
     # sizeof(a_struct) = 40
 6   mov    0x8(%rax), %rdx
     # %rdx = %rax + 0x8 = bp + 40 * i + 8，指向结构体或者说 idx
     # first 占 8 个字节
 7   movslq %ecx, %rcx
     # mov 符号扩展，n 从双字扩展到四字，x 元素类型为 long
 8   mov    %rcx, 0x10(%rax, %rdx, 8)
     # (%rax + 8 * %rdx + 16) = %rcx, long 8字节, 16 = 8 first 长 + 8 idx 长
 9   retq

 A. CNT = (288 - 8) / 40 = 7
 B. typedef struct {
     long idx;
     long x[4];
 }
 */