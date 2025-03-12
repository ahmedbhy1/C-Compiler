.globl main
main:
    subq $4, %rsp
    movl $22, (%rsp)
    movl (%rsp), %eax
    addq $4, %rsp
    ret