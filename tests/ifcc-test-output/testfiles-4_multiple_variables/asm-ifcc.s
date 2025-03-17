.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    movl $1, -0(%rbp)
    subq $4, %rsp
    movl $2, -4(%rbp)
    movl $23, -0(%rbp)
    movl -0(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
