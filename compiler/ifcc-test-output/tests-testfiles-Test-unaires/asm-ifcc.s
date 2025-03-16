.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    movl $0, -0(%rbp)
    subq $4, %rsp
    movl $0, -4(%rbp)
    subq $4, %rsp
    movl $-2, -8(%rbp)
    subq $4, %rsp
    movl $0, -12(%rbp)
    movl -0(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
