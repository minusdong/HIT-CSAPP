/*
 3.73Ã‚
 find_range:
    vxorps %xmm1, %xmm1, %xmm1
    vucomiss %xmm1, %xmm0
    jp .L1
    ja .L2
    jb .L3
    je .L4
    .L2:
    movl $2, %eax
    jmp .Done
    .L3:
    movl $0, %eax
    jmp .Done
    .L4:
    movl $1, %eax
    jmp .Done
    .L1:
    movl $3, %eax
    .Done
 */