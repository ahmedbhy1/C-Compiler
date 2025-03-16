.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    movl $8, -0(%rbp)
    movl -0(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
