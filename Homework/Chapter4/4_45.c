/*
 4.45题：
 A. 不正确，当 REG 为 %rsp 时，显然在第一行就对初始的 %rsp 减了 8，所以压入的是 %rsp - 8。
 B. movq    REG, -8(%rsp)
    subq    $8, %rsp
 */