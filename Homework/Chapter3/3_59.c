/*
3.59题
计算两个 64 位有符号值 x 和 y 的 128 位乘积
当 x 和 y 都是128位时：
x = 2^64 * xk + xi ，其中 xi 表示低 64 位，xk 表示高 64 位
y = 2^64 * yk + yi ，其中 yi 表示低 64 位，yk 表示高 64 位
x * y = (2^64 * xk + xi) * (2^64 * yk + yi)
      = xk * yk * 2^128 + (xk * yi + xi * yk) * 2^64 + xi * yi
      = (xk * yi + xi * yk) * 2^64 + xi * yi ，超出128位的部分舍去
      = (xk * yi + xi * yk + zk) * 2^64 + zi ，其中 zi 是没有超出64位的部分，zk 是超出的部分

   y in %rdx, x in %rsi
 store_prod:
    movq    %rdx, %rax           # %rax = %rdx (%rax = yi)
    cqto                         # %rdx 设置为 %rax 的符号扩展位，即 %rdx = yk
    movq    %rsi, %rcx           # %rcx = %rsi (%rcx = xi)
    sarq    $63, %rcx            # %rcx 右移63位，为 y 的符号扩展位，即 %rcx = xk
    imulq   %rax, %rcx           # %rcx = %rax * %rcx = yi * xk 有符号乘法，截取到64位
    imulq   %rsi, %rdx           # %rdx = %rdx * %rsi = yk * xi 有符号乘法，截取到64位
    addq    %rdx, %rcx           # %rcx = xk * yi + xi * yk
    mulq    %rsi                 # R[%rdx]:R[%rax] <- %rsi*R[%rax] 无符号全乘法, 高位 %rdx = zk，低位 %rax = zi
    addq    %rcx, %rdx           # %rdx = %rdx + %rcx = xk * yi + xi * yk + zk
    movq    %rax, (%rdi)         # 低64位 %rax 放在低地址
    movq    %rdx, 8(%rdi)        # 高64位 %rdx 放在高地址
    ret
 */