.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $8, %eax
    movl %eax, -0(%rbp)
    movl -0(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
